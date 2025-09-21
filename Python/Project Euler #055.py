# Convirtiendo de Project Euler #055.c
# Solución para el problema #55 de Project Euler
# https://projecteuler.net/problem=55

def is_palindrome(n: int) -> bool: # Comprueba si n es un palíndromo
    s = str(n)
    return s == s[::-1]


def is_lychrel(n: int) -> bool: # Comprueba si n es un número Lychrel (no genera palíndromos en menos de 50 iteraciones
    if n < 10:
        return False  # Números de un sólo dígito no se consideran Lychrel

    total = n
    for _ in range(50):
        reverse = int(str(total)[::-1])
        total += reverse
        if is_palindrome(total):
            return False  # Palíndromo encontrado
    return True  # No se encuentra palíndromo en 50 iteraciones


def main():
    respuesta = 0
    for i in range(1, 10001):
        if is_lychrel(i):
          respuesta += 1
          print(i, ") Respuesta: ", respuesta)
    print("La respuesta es ", respuesta)


if __name__ == "__main__":
    main()
