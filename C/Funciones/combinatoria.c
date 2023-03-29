//Función usada en Project Euler #53

int combinatoria(int num, int den){ //Devuelve 1 si excede un millón, devuelve 0 de lo contrario. Devuelve -1 en caso de error (den > num)
    if (den > num) return -1; //No se permiten denominadores mayores que los numeradores
    int diff = (num - den), producto = 1, i = 1, aux2 = den; //Se declara diff como (n-r), una variable para el producto y un contador que irá sumando el factorial del denominador;  aux = num
    //Se guarda una variable aux para guardar el num original
    if  (diff > den){ //Si la diferencia es mayor al denominador, cambian los roles
        den = diff;
        diff = aux2;
    }
    for ( ; num > den; num--){
        producto *= num;
        while ((producto % i == 0) && (i <= diff)){ //Cuando sea posible, se tomará parte del factorial del denominador y dividirlo arriba
            producto /= i;
            i++;
        }
        if (producto > 1000000){
            //printf("Num:%d Dem:%d", aux, den);
            //getchar();
            return 1; //Si el producto llega a ser mayor a un millón, la función se detiene y devuelve verdadero
        }
    }
    return 0;
}
