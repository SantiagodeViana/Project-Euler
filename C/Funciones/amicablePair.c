//Función usada en Project Euler #21 y mencionada en #95

int amicablePair(int n, int m){ //La función confirma si la suma de los divisores del par introducido es igual al otro número, formando un "par amigable"
    int i = 1, div = 0; //Índice y suma de divisores
    int amicableN = 1, amicableM = 1; //Booleanos para confirmar si los números son "amigables" por cuenta propia
    if (n == m){
        amicableN = 0;
        amicableM = 0;
    }
    while (amicableN == 1 && i <= (n/2)){ //Se comienza confirmando si n es "amigable"
        if (n % i == 0){
            div += i;
            if (div > m) amicableN = 0; //Se detiene la búsqueda si la suma de divisores
        }
        i++;
    }
    if (div == m){
        div = 0;
        i = 1; //Reiniciando variables
        while (amicableM == 1 && i <= (m/2)){ //Se comienza confirmando si n es "amigable"
            if (m % i == 0){
                div += i;
                if (div > n) amicableM = 0; //Se detiene la búsqueda
            }
            i++;
        }
        if (div != n) amicableM = 0;
    } else amicableN = 0;
    return (amicableN && amicableM);
}
