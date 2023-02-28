# Solución para el problema #48 de Project Euler
# "Encuentra los diez últimos dígitos de la serie, 1^1 + 2^2 + 3^3 + ... + 1000^1000."
# https://projecteuler.net/problem=48

base = 1
suma = 0
while base < 1000: #Calcula la serie
	suma += (base ** base)
	base += 1
print ("La respuesta es: ") #La respuesta es 9110846700
print (suma % 10000000000) #Se agarran los diez últimos digitos de la potencia
