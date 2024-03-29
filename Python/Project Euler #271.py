#Project Euler 271

def modCubo(n):
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

#n = 91
n = 13082761331670030
print("La respuesta es:", modCubo(n))
