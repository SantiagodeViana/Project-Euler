# Función usada en Project Euler #387

def digit_sum(n: int) -> int:
    suma = 0
    while n > 0:
        suma += n % 10
        n //= 10
    return suma
