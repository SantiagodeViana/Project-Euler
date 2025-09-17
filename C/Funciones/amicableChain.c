//Función usada en Project Euler #95

int amicableChain(long long int n, long long int ref){ //Devuelve la "longitud" de la cadena "amigable". Ref debe inicializarse como -1
    int i = 1, longitud = 0; //Índice, suma de divisores y longitud de cadena
    long long int div = 0;
    while (i <= (n/2)){
        if (n % i == 0) div += i;
        i++;
    }
    //Paso base: no hay ciclo. La mayoría de los números no devuelven ciclos, incluyendo a los números "perfectos"
    //PE #95 también excluye aquellas cadenas con elementos superiores a un millón
    if (div == n || div == 0 || div > 1000000) return 0;
    else if (div == ref) return 1; //Pase base: ciclo encontrado. Devuelve 1 si se halla el n original
    else if (amicablePair(n, div) != 1){ //Se agrega condición para evitar pares amigables y así evitar bucles. Pendiente de considerar ternas.
        if (ref == -1) ref = n; //En caso de ser el primer paso, sse declara la variable de referencia
        //printf("Ref %lld, n: %lld, div: %lld\n", ref, n, div);
        //getchar();
        longitud = amicableChain(div, ref);
        return longitud + (longitud && 1); //Llamada recursiva: 0 si no hay ciclo, devuelve longitud + 1 en caso de continuar
    }
    else return 0;
}
