public class Carta {
    private String valor; // carta de 1 a 10
    private String cara;

    public Carta(String valor, String cara) {
        this.valor = valor;
        this.cara = cara;
    }

    public int getValor(String valor){
        int num = -1;
        if (valor == "A") num = 14;
        else if (valor == "K") num = 13;
        else if (valor == "Q") num = 12;
        else if (valor == "J") num = 11;
        else if (valor == "10") num = 10;
        else if (valor == "9") num = 9;
        else if (valor == "8") num = 8;
        else if (valor == "7") num = 7;
        else if (valor == "6") num = 6;
        else if (valor == "5") num = 5;
        else if (valor == "4") num = 4;
        else if (valor == "3") num = 3;
        else if (valor == "2") num = 2;
        return num;
    }

    public String getCara(){
        return this.cara;
    }
}
