# Solución para el problema #16 de Project Euler
# "¿Cuál es la suma de los dígitos del número 2^1000?"
# https://projecteuler.net/problem=16

def sum_digits(n):
    s = 0 #Variable suma
    while n:
        s += n % 10 #Se suman los digitos, uno por uno
        n //= 10
    return s

x = 2**1000

print(x)
print("La respuesta es: ") #La respuesta es 1366
print(sum_digits(x))
