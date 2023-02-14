# Función usada en Project Euler #016 y #20

def sum_digits(n):
    s = 0 #Variable suma
    while n:
        s += n % 10 #Se suman los digitos, uno por uno
        n //= 10
    return s
