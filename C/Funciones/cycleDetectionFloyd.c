//Algoritmo de detección de ciclos de Floyd basado en el problema Project Euler #74
int cycleDetection(int n){ //Devuelve la longitud del ciclo más pequeño
    int tortuga, liebre, pasos = 0, longitud = 1, i = 0; 
    if (n == 145 || n == 40585) return 0; //digitFactorial(n)= n cuando = 145 o 40585, no producen términos no repetitivos
    else{
        tortuga = digitFactorial(n);
        liebre = digitFactorial(digitFactorial(n);
        while (tortuga != liebre){ //Se busca el ciclo
            tortuga = digitFactorial(tortuga); //Tortuga: un paso
            liebre = digitFactorial(digitFactorial(liebre)); //Liebre: dos pasos
        }
        tortuga = n; //La tortuga vuelve al comienzo
        while (tortuga != liebre){ //Se calculan los pasos denotan antes de que empiece el ciclo
            tortuga = digitFactorial(tortuga);
            liebre = digitFactorial(liebre); //Tortuga y liebre ahora a misma velocidad
            pasos++;
        }
        liebre = digitFactorial(tortuga);
        while (tortuga != liebre){
            liebre = digitFactorial(liebre); //Se calcula la longitud del ciclo
            longitud++;
        }
    }
    return longitud;
}
