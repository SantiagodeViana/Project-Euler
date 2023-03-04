int Euclides (int n, int m){ //Regresa MCD de a y b, donde 0 < b <= a
    int a = n, b = m; //De manera predeterminada se asume que n es mayor que m
    if (a == b) return a; //Si a = b, son iguales al MCD
    if ((a%2 == 0) && (b%2 ==0)) return 2; //Ad hoc: Ambos números pares, es reducible
    //if (a < 0) a *= (-1); //Si a es negativo, se convierte en positivo
    //if (b < 0) a *= (-1); //Si b es negativo, se convierte en positivo
    else if (n < m){ //Si n es menor que m,
        a = m;
        b = n;
    }
    while ((a != 0) && (b != 0) && (a != 1) && (b != 1) && (a % b != 0)){ //Los restos se van turnando, de mayor a menor; // && (b % a != 0 &&
        if ((b != 0) && (a != 1) && (b != 1)) a = (a % b);
        if ((a != 0) && (a != 1) && (b != 1)) b = (b % a);
    }
    if (b == 0) return a; //En el caso de los pares, devolver el resto diferente de 0
    else if (a == 0) return b; //En el caso de los pares, devolver el resto diferente de 0
    else if (a < b) return a;
    else if (b < a) return b;
    return 1;
}
