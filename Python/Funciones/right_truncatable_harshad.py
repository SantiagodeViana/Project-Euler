# Función usada en Project Euler #387

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
