# Función usada en Project Euler #387

def digitos(n: int) -> int:
    respuesta = 0
    i = 1
    while i <= n:
        i *= 10
        respuesta += 1
    return respuesta
