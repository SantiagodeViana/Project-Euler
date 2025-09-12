# Project Euler 271:
# 
# "Para un número positivo n, definimos S(n) como la suma de los enteros x tales que 1 < x < n y x³ ≡ 1 (mod n).
# Cuando n = 91, existen 8 posibles valores para x, a saber: 9, 16, 22, 29, 53, 74, 79, 81.
# Así, S(91) = 9 + 16 + 22 + 29 + 53 + 74 + 79 + 81 = 363.
# Encuentra S(13082761331670030).
# 
#https://projecteuler.net/problem=271

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
