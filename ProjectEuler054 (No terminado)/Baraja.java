public class Baraja {
    private Carta[] cartas;

    public Baraja(Carta carta1, Carta carta2, Carta carta3, Carta carta4, Carta carta5) {
        this.cartas = new Carta[5];
        cartas[0] = carta1;
        cartas[1] = carta2;
        cartas[2] = carta3;
        cartas[3] = carta4;
        cartas[4] = carta5;
    }
}
