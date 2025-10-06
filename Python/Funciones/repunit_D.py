def repunit_D(n): # Devuelve el valor A(n), el menor valor del largo k en R(k) # en el que un repunit es divisible por n
    A = 1
    r = 1
    while (n > r) or (r % n != 0): # Mientras n sea mayor que r o no sea divisible por el repunit
        r *= 10
        r += 1
        A += 1
    return A
