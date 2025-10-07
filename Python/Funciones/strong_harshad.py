# Función usada en Project Euler #387

def strong_harshad(n: int) -> int:
    suma = digit_sum(n)
    if n % suma != 0:
        return 0
    elif n < 10:
        return 0
    elif is_prime(n // suma) == 1:
        return 1
    return 0
