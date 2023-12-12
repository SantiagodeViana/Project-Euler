respuesta = 0

#Código convertido de C con ChatGPT

for x in range(1, 1500001):
    for y in range(x + 1, 1500001):
        for z in range(y + 1, 1500001):
            xC, yC, zC = x * x, y * y, z * z
            if xC + yC == zC:
                respuesta += 1
                print(f"Respuesta: {respuesta} - {x+y+z} - x: {x} y: {y} z: {z}")
            # print(f"x: {x} y: {y} z: {z}")

print(f"La respuesta es: {respuesta}")
print("Fin del programa.")
