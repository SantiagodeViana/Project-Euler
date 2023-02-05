int XOR(int n, int m){ //Recibe dos números binarios y aplica la operación lógica XOR con ellos
    //Evitar entradas con leading zeros: por alguna razón causa la entrada del parámetro como un número decimal
    int i, respuesta = 0, baseB = 1;  // ***** i = digitos
    if (digitos(n) >= digitos(m)) for (i=1; i<digitos(n); i++) baseB*=10; //Se calcula divisor
    else if (digitos(n) < digitos(m)) for (i=1; i<digitos(m); i++) baseB*=10;
    while(baseB >= 1){
        if ((n/baseB) != (m/baseB)) respuesta += baseB; // A != B => 1
        //else if ((n/baseB) == (m/baseB)) respuesta *= 10; //else if ((n/baseB) == (m/baseB))
        if (n >= baseB) n %= baseB; //Se "recortan" las entradas
        if (m >= baseB) m %= baseB;
        baseB /= 10; //En el caso de que sean iguales, el 0 es implícito
    }
    return respuesta;
}
