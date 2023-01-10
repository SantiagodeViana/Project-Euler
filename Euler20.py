def sum_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s

respuesta = 1
x = 1
while x <= 100:
	respuesta *= x
    	x += 1
    	print respuesta
        
print sum_digits(respuesta)