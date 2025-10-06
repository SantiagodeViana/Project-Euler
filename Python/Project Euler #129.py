# Solución para problema #129 de Project Euler
# "Encuentra el valor más pequeño de n para el cual A(n) excede por primera vez un millón."
# https://projecteuler.net/problem=129

def euclides(n, m):
    # Regresa MCD de a y b, donde 0 < b <= a
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

def repunit_D(n): # Devuelve el valor A(n), el menor valor del largo k en R(k) # en el que un repunit es divisible por n
    A = 1
    r = 1
    while (n > r) or (r % n != 0): # Mientras n sea mayor que r o no sea divisible por el repunit
        r *= 10
        r += 1
        A += 1
    return A

def main():
    i = 999950
    respuesta = 0
    while respuesta < 1000000:
        if euclides(i, 10) == 1:  # i debe ser coprimo de 10 para poder ser un dividor
            A = repunit_D(i)
            if A > respuesta:
                respuesta = i
                print(f"A({i}) = {A}")
        i += 1
    print(f"La respuesta es {respuesta}")


if __name__ == "__main__":
    main()
