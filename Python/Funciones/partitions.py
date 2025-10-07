# Función usada en Project Euler #078

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
