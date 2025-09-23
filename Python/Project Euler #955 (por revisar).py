import math

#Convertirdo de Project Euler #955.c

def is_triangle(n: int) -> bool: # Comprueba si n es triangular
    d = 1 + 8*n
    s = math.isqrt(d)
    return s*s == d and (s - 1) % 2 == 0

def main():
    i = 0
    t = 1  # t cuenta números triangulares
    an = 4
    am = 3
    while t < 70:
        aux = an  # Se guarda valor actual
        if is_triangle(an):
            t += 1
            print(f"{t}) {an} Respuesta: {i}")
            an += 1
        else: an = (2*an) - am + 1  # 2an - an-1 + 1
        am = aux  # Se actualiza el valor previo
        if t < 70: i += 1
    print(f"La respuesta es {i}")

if __name__ == "__main__":
    main()
