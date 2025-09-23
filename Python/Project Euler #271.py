# Project Euler 271:
# 
# "Para un número positivo n, definimos S(n) como la suma de los enteros x tales que 1 < x < n y x³ ≡ 1 (mod n).
# Cuando n = 91, existen 8 posibles valores para x, a saber: 9, 16, 22, 29, 53, 74, 79, 81.
# Así, S(91) = 9 + 16 + 22 + 29 + 53 + 74 + 79 + 81 = 363.
# Encuentra S(13082761331670030).
# 
# https://projecteuler.net/problem=271

def main():
    respuesta = 0 
    for i in range(2, 13082761331670030):
        if (i*i*i) % 13082761331670030 == 1:
            respuesta += i
            print(f"i: {i}")
        if (i) % 10000000 == 0:
            print(f"i: {i}")
    print(f"La respuesta es {respuesta}")

main()
