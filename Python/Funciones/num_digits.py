# Función usada en Project Euler #25

def num_digits(n): #Función que devuelve número de dígitos
	s = 0
	while n:
		s += 1
		n//= 10
	return s
