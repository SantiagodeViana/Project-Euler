# Solución para el problema #173 de Project Euler
# "Usando hasta un millón de baldosas, ¿cuántas láminas cuadradas diferentes pueden formarse?"
# https://projecteuler.net/problem=173
# La condición límite del bucle no funciona, pero la respuesta conseguida es correcta

def main():
    TILES = 1000000
    respuesta = 0
    # TILES < a < b
    for a in range(3, TILES + 1):  # a representa el perímetro y el "grueso" de las láminas
        for b in range(1, (a - 1)):  # a representa el perímetro y el "grueso" de las láminas
            if (((a % 2 == 0 and b % 2 == 0) or (a % 2 != 0 and b % 2 != 0)) and ((a + b) * (a - b) <= TILES)):  # Expresando a^2 - b^2 como (a+b)(a-b)
                respuesta += 1  # a y b deben tener la misma paridad, y no deben exceder la cantidad de casillas.
                print(f"a: {a}  b: {b}  Respuesta: {respuesta}")
    print(f"La respuesta es {respuesta}")

if __name__ == "__main__":
    main()
