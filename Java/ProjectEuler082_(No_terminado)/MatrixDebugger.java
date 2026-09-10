import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;

// Creado con IA
// Observes copies of program state; never writes to the solver's arrays.

public final class MatrixDebugger {
    private static MatrixDebugger instance;
    private final Object gate = new Object();
    private boolean running;
    private boolean stepRequested;
    private volatile int delayMs = 250;
    private final int[][] values;
    private boolean[][] marked;
    private boolean[][] seen;
    private int row = -1, col = -1;
    private long eventNumber;
    private JTable table;
    private JTextArea details;
    private JCheckBox follow;
    private JButton step, play, pause;

    private MatrixDebugger(int[][] matrix) {
        values = new int[matrix.length][];
        marked = new boolean[matrix.length][];
        seen = new boolean[matrix.length][];
        for (int r = 0; r < matrix.length; r++) {
            values[r] = matrix[r].clone();
            marked[r] = new boolean[matrix[r].length];
            seen[r] = new boolean[matrix[r].length];
        }
    }

    // Call from the solver thread (Main.main), never from the Swing event thread.
    public static void open(int[][] matrix) {
        if (GraphicsEnvironment.isHeadless())
            throw new IllegalStateException("The visual debugger needs a desktop display.");
        instance = new MatrixDebugger(matrix);
        onUi(() -> instance.buildWindow());
    }

    public static void show(boolean[][] visited, int i, int nivel,
                            int accumulated, int best, int c, String event) {
        if (instance == null) return;
        MatrixDebugger d = instance;
        boolean[][] snapshot = new boolean[visited.length][];
        for (int r = 0; r < visited.length; r++) snapshot[r] = visited[r].clone();
        onUi(() -> d.display(snapshot, i, nivel, accumulated, best, c, event));
        d.awaitAdvance();
    }

    public static void finish() {
        if (instance == null) return;
        onUi(() -> {
            instance.details.append("\nFinished. Last checkpoint remains visible.");
            instance.step.setEnabled(false);
            instance.play.setEnabled(false);
            instance.pause.setEnabled(false);
        });
    }

    private static void onUi(Runnable action) {
        if (SwingUtilities.isEventDispatchThread())
            throw new IllegalStateException("Run the solver outside the Swing event thread.");
        try { SwingUtilities.invokeAndWait(action); }
        catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new RuntimeException(e);
        } catch (java.lang.reflect.InvocationTargetException e) {
            throw new RuntimeException(e.getCause());
        }
    }

    private void awaitAdvance() {
        synchronized (gate) {
            long deadline = System.nanoTime() + delayMs * 1_000_000L;
            for (;;) {
                if (stepRequested) { stepRequested = false; return; }
                try {
                    if (!running) {
                        gate.wait();
                        deadline = System.nanoTime() + delayMs * 1_000_000L;
                    } else {
                        long remaining = deadline - System.nanoTime();
                        if (remaining <= 0) return;
                        gate.wait(Math.max(1L, remaining / 1_000_000L));
                    }
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    throw new RuntimeException(e);
                }
            }
        }
    }

    private void buildWindow() {
        JFrame frame = new JFrame("Matrix debugger | PathSum");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        step = new JButton("Step"); play = new JButton("Run"); pause = new JButton("Pause");
        step.addActionListener(e -> { synchronized (gate) {
            running = false; stepRequested = true; gate.notifyAll();
        }});
        play.addActionListener(e -> { synchronized (gate) {
            running = true; stepRequested = false; gate.notifyAll();
        }});
        pause.addActionListener(e -> { synchronized (gate) {
            running = false; stepRequested = false; gate.notifyAll();
        }});
        JPanel controls = new JPanel(new FlowLayout(FlowLayout.LEFT));
        controls.add(step); controls.add(play); controls.add(pause);
        controls.add(new JLabel("Delay (ms):"));
        JSpinner delay = new JSpinner(new SpinnerNumberModel(250, 10, 5000, 50));
        delay.addChangeListener(e -> delayMs = (Integer) delay.getValue());
        controls.add(delay);
        follow = new JCheckBox("Follow current cell", true); controls.add(follow);
        JCheckBox numbers = new JCheckBox("Show values", true); controls.add(numbers);
        JSpinner zoom = new JSpinner(new SpinnerNumberModel(64, 16, 120, 8));
        controls.add(new JLabel("Cell width:")); controls.add(zoom);

        table = new JTable(new AbstractTableModel() {
            public int getRowCount() { return values.length; }
            public int getColumnCount() { return values[0].length; }
            public String getColumnName(int column) { return Integer.toString(column); }
            public Object getValueAt(int r, int c) { return values[r][c]; }
        });
        table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
        table.setRowHeight(30);
        table.setCellSelectionEnabled(false);
        table.setFocusable(false);
        table.getTableHeader().setReorderingAllowed(false);
        table.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            public Component getTableCellRendererComponent(JTable t, Object value,
                    boolean selected, boolean focus, int r, int c) {
                super.getTableCellRendererComponent(t, value, false, false, r, c);
                setHorizontalAlignment(SwingConstants.CENTER);
                setText(numbers.isSelected() ? String.valueOf(value) : "");
                setBackground(marked[r][c] ? new Color(96, 200, 163)
                        : seen[r][c] ? new Color(222, 231, 241) : Color.WHITE);
                setForeground(new Color(25, 36, 48));
                setBorder(r == row && c == col
                        ? BorderFactory.createLineBorder(new Color(232, 112, 20), 3)
                        : BorderFactory.createEmptyBorder(3, 3, 3, 3));
                setToolTipText("[" + r + "][" + c + "] = " + value
                        + " | visitados=" + marked[r][c] + " | previously marked=" + seen[r][c]);
                return this;
            }
        });
        Runnable resize = () -> {
            int width = (Integer) zoom.getValue();
            for (int c = 0; c < table.getColumnCount(); c++)
                table.getColumnModel().getColumn(c).setPreferredWidth(width);
            table.setRowHeight(Math.max(18, width / 2));
        };
        zoom.addChangeListener(e -> resize.run()); resize.run();
        numbers.addActionListener(e -> table.repaint());
        JScrollPane scroll = new JScrollPane(table);
        JComponent rowLabels = new JComponent() {
            public Dimension getPreferredSize() {
                return new Dimension(42, table.getRowCount() * table.getRowHeight());
            }
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.setColor(Color.DARK_GRAY);
                int h = table.getRowHeight();
                Rectangle clip = g.getClipBounds();
                for (int r = Math.max(0, clip.y / h); r < values.length && r * h < clip.y + clip.height; r++)
                    g.drawString(Integer.toString(r), 8, r * h + h / 2 + 5);
            }
        };
        table.addPropertyChangeListener("rowHeight", e -> { rowLabels.revalidate(); rowLabels.repaint(); });
        scroll.setRowHeaderView(rowLabels);
        details = new JTextArea(4, 60);
        details.setEditable(false);
        details.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 13));
        details.setBorder(BorderFactory.createEmptyBorder(8, 10, 8, 10));
        JPanel bottom = new JPanel(new BorderLayout());
        bottom.add(new JLabel("  Green: visitados=true   |   Gray-blue: previously true   |   Orange outline: i, nivel   |   Indices start at 0"), BorderLayout.NORTH);
        bottom.add(new JScrollPane(details), BorderLayout.CENTER);
        frame.add(controls, BorderLayout.NORTH);
        frame.add(scroll, BorderLayout.CENTER);
        frame.add(bottom, BorderLayout.SOUTH);
        frame.setSize(1150, 750);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

    private void display(boolean[][] snapshot, int i, int nivel, int accumulated,
                         int best, int c, String event) {
        marked = snapshot; row = i; col = nivel;
        int count = 0;
        for (int r = 0; r < marked.length; r++) for (int k = 0; k < marked[r].length; k++) {
            if (marked[r][k]) { seen[r][k] = true; count++; }
        }
        boolean valid = row >= 0 && row < values.length && col >= 0 && col < values[row].length;
        details.setText("Checkpoint " + (++eventNumber) + " | " + event
                + "\ni (row)=" + i + "   nivel (column)=" + nivel + "   c=" + (c < 0 ? "n/a" : c)
                + "   matriz[i][nivel]=" + (valid ? values[row][col] : "n/a")
                + "\nvalorAcumulado=" + accumulated + "   sol.getSolucion()=" + best
                + "   marked cells=" + count);
        table.repaint();
        if (follow.isSelected() && valid) table.scrollRectToVisible(table.getCellRect(row, col, true));
    }
}
