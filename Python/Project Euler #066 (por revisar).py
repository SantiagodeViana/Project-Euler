import math

def main():
    # Forma a^2 - Db^2 = k
    respuesta = 0
    max_val = 0

    for D in range(2, 1001):
        a = math.isqrt(D)  # floor(sqrt(D))
        b = 1
        k = (a * a) - (D * b * b)

        # Los condiciones de parada pueden ser k = +-1, k=+-2 o k+-4
        # También se contempla el caso en el que D es un cuadrado, donde k = 0 y no hay soluciones
        while (k != 0 and k != 1 and k != -1):  # && k != 2 && k != -2 && k != 4 && k != -4
            m = D
            for aux in range(1, D + 1):
                if ((a + b * aux) % k == 0) and (abs(aux * aux - D) < abs(m * m - D)):
                    m = aux
            # Iteraciones para actualizar valores
            aux = (a * m + D * b) // abs(k)
            b = (a + b * m) // abs(k)
            k = (m * m - D) // k
            a = aux
            # print(f"Triple: ({a}, {b}, {k})")

        if k != 0:
            # En este problema sólo preguntan por x, por lo que no se calculará y
            x = ((a * a) + (D * b * b)) // abs(k)  # x = a^2 + Dy^2
            # y = 2 * a * b
            if x > max_val:
                max_val = x
                respuesta = D  # La respuesta será D que ofrezca el mayor valor de x en el intervalo
            print(f"D:{D}, x:{x}, Respuesta:{respuesta} (x: {max_val})")

if __name__ == "__main__":
    main()
