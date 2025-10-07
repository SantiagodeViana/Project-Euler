# Función usada en Project Euler #062

def digit_count(n):
    count = 0
    i = 1
    while i <= n:
        i *= 10
        count += 1
    return count
