# Función usada en Project Euler #387

def is_right_truncatable_strong_harshad_prime(n: int) -> int:
    if is_prime(n) != 1:
        return 0
    elif n < 10:
        return 0
    else:
        n //= 10
        if is_strong_harshad(n) == 1 and is_right_truncatable_harshad(n) == 1:
            return 1
    return 0
