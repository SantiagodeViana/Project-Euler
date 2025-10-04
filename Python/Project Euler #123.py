import math

# Solución para el problema #123 de Project Euler
# "Encuentra el valor más pequeño de n para el cual el resto exceda por primera vez 10¹⁰."
# https://projecteuler.net/problem=123

def is_prime(n):
    if n == 1:
        return False
    elif n < 4:
        return True
    elif n % 2 == 0:
        return False
    elif n < 9:
        return True
    elif n % 3 == 0:
        return False
    else:
        r = int(math.isqrt(n))
        f = 5
        while f <= r:
            if n % f == 0:
                return False
            elif n % (f + 2) == 0:
                return False
            f += 6
        return True


def main():
    n = 2 # n cuenta la cantidad (índice) de primos
    respuesta = 0
    r = 0
    max = 0 #max registra el resto máximo obtenido
    i = 5 

    while max < 10**10:
        if is_prime(i):
            n += 1
            a = i - 1
            for _ in range(1, n):
                a *= (i - 1)  # (pn - 1)^n, se elevan las expresiones las veces necesarias

            b = i + 1
            for _ in range(1, n):
                b *= (i + 1)  # (p_n + 1)^n

            suma = a + b
            r = suma % (i * i)

            if r > max: #(pn - 1)^n + (pn + 1)^n % pn^2
                max = r # Almacenando resto màximo
                respuesta = n
                print(f"Respuesta {respuesta} ({i} = {max_r})")

        i += 1

    print(f"La respuesta es {respuesta}")


if __name__ == "__main__":
    main()
