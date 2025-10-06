# Función usada en Project Euler #271

def mod_cubo(n):
    suma = 0
    for i in range(2, n, 1):  # Sola cuenta números impares
        aux = i
        for j in range(2):  # x^2 mod n
            aux %= n
            aux *= i
        if aux % n == 1:
            suma += i  # suma += x
            print("x:", i)
    return suma
