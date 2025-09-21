//Algoritmo de detección de ciclos de Brent basado en el problema Project Euler #95
//El algoritmo de Brent hace muchas menos llamadas a funciones y ahorra tiempo de resolución

int cycleDetection(int n){ //Devuelve la "longitud" de la cadena "amigable".
    int tortuga, liebre, pasos = 0, longitud = 1, pow = 1; //Implementando algoritmo de Brent: 
    int min = n; //Variable sólo para almacenar valor más pequeño conseguido en una cadena, pedido por el problema
    if (divSum(n) == n) return 0; //Los números "perfectos" no generan cadenas
    else{ //Se agrega condición de que ninguno de los elementos supere el millón
        tortuga = n;
        liebre = divSum(n);
        while (tortuga != liebre){
            if (pow == longitud){
                tortuga = liebre; //Tortuga: un paso
                pow *= 2;
                longitud = 0;
            }
            liebre = divSum(liebre);
            longitud++;
        }
        tortuga = n;
        liebre = n;
        for (int i = 1; i <= longitud; i++) liebre = divSum(liebre); //La distancia entre la tortuga y liebre es "longitud"
        while (tortuga != liebre){ //Para ciclos que empiezan en el término inicial este bucle puede eliminarse
            tortuga = divSum(tortuga);
            liebre = divSum(liebre); //Tortuga y liebre ahora a misma velocidad
            if (tortuga < min) min = tortuga;
            pasos++;
        }
        return (pasos + longitud);
    }
}
