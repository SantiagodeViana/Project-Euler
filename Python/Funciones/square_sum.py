def square_sum(n):  # Devuelve suma del cuadrado de los dígitos de n
    suma = 0
    while n > 0:
        suma += (n % 10) * (n % 10)
        n //= 10
    return suma
