# Solución para el problema #178 de Project Euler
# "¿Cuántos números pandigitales menores que 10^40 hay?
# https://projecteuler.net/problem=178       
# El algoritmo actual tarda demasiado en conseguir la respuesta

def is_step_number(n):  # Comprueba si n es un "step number", donde todos los dígitos consecutivos tienen una diferencia de uno entre sí mismos
    step = 1  # Step es una variable booleana.
    if n < 10:
        step = 0  # Se declarán los n de un sólo dígito como no step number
    else:
        aux = n % 10 # Aux almacena el dígito anterior
        n //= 10
        while step == 1 and n > 0:
            if (n % 10 != (aux + 1) and n % 10 != (aux - 1)):
                step = 0  # Se comprueba que haya una diferencia de uno entre los dígitos
            aux = n % 10
            n //= 10
    return step

def main():
    respuesta = 0
    for i in range(1, 10**40 + 1):
        if is_step_number(i) == 1:
            respuesta += 1
        if (i % 1000000 == 0):
            print(f"i: {i} Respuesta: {respuesta}")
    print(f"La respuesta es {respuesta}")
    return 0


if __name__ == "__main__":
    main()
