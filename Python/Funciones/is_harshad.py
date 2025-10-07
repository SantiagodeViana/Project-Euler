# Función usada en Project Euler #387

def is_harshad(n: int) -> int:
    if n % digit_sum(n) == 0:
        return 1
    else:
        return 0
