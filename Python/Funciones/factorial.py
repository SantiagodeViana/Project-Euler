# Función usada en Project Euler #53

def factorial(n): //Función factorial
        if n == 1:
                return 1
        else:
                return factorial(n-1) * n
