# Solución para el problema #48 de Project Euler
# "Encuentra los diez últimos dígitos de la serie, 1^1 + 2^2 + 3^3 + ... + 1000^1000."
# https://projecteuler.net/problem=48

base = 1
suma = 0
while base <= 10: #Calcula la serie
	suma += (base ** base)
	base += 1
    	print base
print suma
