# Función usada en Project Euler #062 y #387

def digit_count(n: int) -> int:
    count = 0
    i = 1
    while i <= n:
        i *= 10
        count += 1
    return count
    
