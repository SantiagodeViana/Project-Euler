import math

def squareSum(n):  # Devuelve suma del cuadrado de los dígitos de n
    suma = 0
    while n > 0:
        suma += (n % 10) * (n % 10)
        n //= 10
    return suma

#  /* Solución del problema #171 de Project Euler
#   * "Encuentra los últimos nueve dígitos de la suma de todos los n, 0 < n < 10^20, tales que f(n) sea un cuadrado perfecto."
#   * https://projecteuler.net/problem=171                   */

def main():
    i = 1
    square = 0
    respuesta = 0
    # f(640000000) = 52 Respuesta: 7302829116635220
    while i <= 100000000000000000000:
        square = squareSum(i)
        if math.isqrt(square) ** 2 == square:  # Comprueba cuadrados perfectos: aquellos cuya raíz sean enteros
            respuesta += i
            #print(f"f({i}) = {square}")
        if (i % 1000000 == 0):
            print(f"f({i}) = {square} Respuesta: {respuesta}")
        i += 1
    print(f"La respuesta es {respuesta}")


if __name__ == "__main__":
    main()
