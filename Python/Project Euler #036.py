# "Encuentra la suma de todos los números, menores que un millón, que son palíndromos en base 10 y base 2."
# https://projecteuler.net/problem=36 

def is_palindrome(s: str) -> bool:
    return s == s[::-1]

suma = 0
for i in range(1, 1_000_000):
    if is_palindrome(str(i)) and is_palindrome(bin(i)[2:]):
        suma += i
suma
