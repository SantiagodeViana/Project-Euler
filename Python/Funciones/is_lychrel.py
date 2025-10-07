#Funciónn usada en Project Euler #055

def is_lychrel(n: int) -> bool: # Comprueba si n es un número Lychrel (no genera palíndromos en menos de 50 iteraciones
    if n < 10:
        return False  # Números de un sólo dígito no se consideran Lychrel

    total = n
    for _ in range(50):
        reverse = int(str(total)[::-1])
        total += reverse
        if is_palindrome(total):
            return False  # Palíndromo encontrado
    return True  # No se encuentra palíndromo en 50 iteraciones
