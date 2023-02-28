# Solución para el problema #25 de Project Euler
# "¿Cuál es el índice del primer término de la sucesión de Fibonacci que contiene 1000 cifras?"
# https://projecteuler.net/problem=25

def num_digits(n): #Función que devuelve número de dígitos
	s = 0
	while n:
		s += 1
		n//= 10
	return s
n1 = 0 
n2 = 0
x = 0
respuesta = 0

while num_digits(x) < 1000: #Se busca en la secuencia 
   	x = n1 + n2 #Secuencia Fibonacci
   	if x == 0:
   		x += 1
   	respuesta += 1
   	n2 = n1
   	n1 = x

print ("La respuesta es: ") #La respuesta es 4782
print (respuesta)
