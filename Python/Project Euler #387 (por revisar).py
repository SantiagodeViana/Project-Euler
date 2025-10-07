import math

# Solución para el problema #387 de Project Euler
# https://projecteuler.net/problem=387
# Código convertido del programa equivalente en C con ChatGPT

# "Respuesta:130459097 i:80402071"

def is_prime(n: int) -> int:
    if n == 1:
        return 1  # (could be 0, depending on your intended definition)
    elif n < 4:
        return 1  # 2 and 3 are prime
    elif n % 2 == 0:
        return 0
    elif n < 9:
        return 1  # 5 and 7 are prime
    elif n % 3 == 0:
        return 0
    else:
        r = int(math.isqrt(n))  # floor(sqrt(n))
        f = 5
        while f <= r:
            if n % f == 0:
                return 0
            elif n % (f + 2) == 0:
                return 0
            f += 6
        return 1

def digitos(n: int) -> int:
    respuesta = 0
    i = 1
    while i <= n:
        i *= 10
        respuesta += 1
    return respuesta

def digit_sum(n: int) -> int:
    suma = 0
    while n > 0:
        suma += n % 10
        n //= 10
    return suma

def is_harshad(n: int) -> int:
    if n % digit_sum(n) == 0:
        return 1
    else:
        return 0

def right_truncatable_harshad(n: int) -> int:
    i = 1
    if n < 10:
        return 0
    else:
        while i < n:
            j = n // i
            if is_harshad(j) == 0:
                return 0
            i *= 10
    return 1

def strong_harshad(n: int) -> int:
    suma = digit_sum(n)
    if n % suma != 0:
        return 0
    elif n < 10:
        return 0
    elif is_prime(n // suma) == 1:
        return 1
    return 0

def right_truncatable_strong_harshad_prime(n: int) -> int:
    if is_prime(n) != 1:
        return 0
    elif n < 10:
        return 0
    else:
        n //= 10
        if strong_harshad(n) == 1 and right_truncatable_harshad(n) == 1:
            return 1
    return 0


if __name__ == "__main__":
    respuesta = 0
    for i in range(1, 100000000000001):
        if right_truncatable_strong_harshad_prime(i) == 1:
            respuesta += i
            print(f"Respuesta:{respuesta} i:{i}")
