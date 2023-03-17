import sys
sys.setrecursionlimit(10000)

# Solución para el problema #53 de Project Euler
# "¿Cuántos valores, no necesariamente distintos, son mayores que un millón?"
# https://projecteuler.net/problem=53

def factorial(n):
        if n == 1:
                return 1
        else:
                return factorial(n-1) * n
        
n = 0
r = 0
c = 0

while n <= 100:
    if r < n:
    	r += 1
    elif r >= n:
        n += 1
        r = 2
        c = (factorial(n) / (factorial(r) * factorial(n - r)))
    if c > 1000000:
        answer += 1
        print (answer)

#Optimizar, iteración y no recursión
