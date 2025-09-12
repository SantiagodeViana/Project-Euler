# Solución para el problema #78 de Project Euler
# https://projecteuler.net/problem=78
#
# Python llega al máximo de llamadas recursivas cuando n = 1000. Debe considerar resolverse el problema de manera iterativa

N = 5000 

def partitions(n: int, k: int, memo: list[list[int]]) -> int: # Devuelve el número de particiones de n usando D&C. Diseñado para PE #76, #77 y #78.
    if n == 0:
        return 1
    elif n < 0 or k == 0:
        return 0
    elif memo[n][k] != -1:
        return memo[n][k]
    else:
        memo[n][k] = partitions(n, k - 1, memo) + partitions(n - k, k, memo)
        return memo[n][k]

def main():
    n = 1
    respuesta = -1    
    memo = [[-1 for _ in range(N)] for _ in range(N)] # Inicializando la matriz memo con -1

    while respuesta == -1:
        p = partitions(n, n, memo)
        if p % 1_000_000 == 0:
            respuesta = n
        else:
            n += 1
        print(f"p({n}): {p}, respuesta: {respuesta}")

    print(f"La respuesta es {respuesta}")

if __name__ == "__main__":
    main()
