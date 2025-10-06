def euclides(n, m): # Regresa MCD de a y b, donde 0 < b <= a
    a = n
    b = m  # De manera predeterminada se asume que n es mayor que m
    if a == b:
        return a  # Si a = b, son iguales al MCD
    if (a % 2 == 0) and (b % 2 == 0):
        return 2  # Ad hoc: Ambos números pares, es reducible
    # if (a < 0): a *= (-1)  # Si a es negativo, se convierte en positivo
    # if (b < 0): a *= (-1)  # Si b es negativo, se convierte en positivo
    elif n < m:  # Si n es menor que m,
        a = m
        b = n
    while (a != 0) and (b != 0) and (a != 1) and (b != 1) and (a % b != 0):
        # Los restos se van turnando, de mayor a menor; // && (b % a != 0 &&
        if (b != 0) and (a != 1) and (b != 1):
            a %= b
        if (a != 0) and (a != 1) and (b != 1):
            b %= a
    if b == 0:
        return a  # En el caso de los pares, devolver el resto diferente de 0
    elif a == 0:
        return b  # En el caso de los pares, devolver el resto diferente de 0
    elif a < b:
        return a
    elif b < a:
        return b
    return 1
