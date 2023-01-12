def num_digits(n): #Número de dígitos
	s = 0
	while n:
		s += 1
		n//= 10
	return s
n1 = 0 
n2 = 0
x = 0
respuesta = 0
while num_digits(x) < 1000: #Secuencia Fibonacci
   	x = n1 + n2
   	if x == 0:
   		x += 1
   	respuesta += 1
    	n2 = n1
   	n1 = x
print respuesta
