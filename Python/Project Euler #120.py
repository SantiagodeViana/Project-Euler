import sys

# Convirtiendo de Project Euler #120.c
# Solución para el problema 120 de Project Euler
# https://projecteuler.net/problem=120

def main():
    respuesta = 0 
    for i in range(3, 1001):  # a from 3 to 1000
        a = i - 1
        b = i + 1
        max_r = 0
        n = 0 # n es el exponente y r el resto
        while n < 10000:
            a *= (i - 1)  # (a-1)^n
            b *= (i + 1)  # (a+1)^n
            suma = a + b # (a-1)^n + (a+1)^n
            r = suma % (i * i)
            if r > max_r:
                max_r = r
            n += 1
        respuesta += max_r
        print(f"a: {i}, n:{n}, max: {max_r} Respuesta: {respuesta}")

if __name__ == "__main__":
    main()
