# Solución para el problema #20 de Project Euler
# "Encuentra la suma de los dígitos del número 100!"
# https://projecteuler.net/problem=20

def sum_digits(n):
    s = 0 #Variable suma
    while n:
        s += n % 10 #Se suman los digitos, uno por uno
        n //= 10
    return (s)

respuesta = 1
x = 1
while x <= 100:
    respuesta *= x
    x += 1
    print (respuesta)
  
print ("La respuesta es: ") #La respuesta es 648
print (sum_digits(respuesta))
