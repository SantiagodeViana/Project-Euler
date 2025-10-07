#Función usada en Project Euler #036

def is_palindrome(s: str) -> bool:
    return s == s[::-1]
