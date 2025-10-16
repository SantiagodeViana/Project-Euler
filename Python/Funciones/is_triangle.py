#Función usada en Project Euler #955

def is_triangle(n: int) -> bool: # Comprueba si n es triangular
    d = 1 + 8*n
    s = math.isqrt(d)
    return s*s == d and (s - 1) % 2 == 0
