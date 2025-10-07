# Función usada en Project Euler #062

def is_permutable(n, m, length):
    digits = [int(d) for d in str(n)]
    if n == m:
        return 0
    for i in range(length):
        temp = digits[i]
        temp2 = m
        count, count2 = 0, 0
        for j in range(length):
            if digits[j] == temp:
                count += 1
        while temp2 != 0:
            if temp2 % 10 == temp:
                count2 += 1
            temp2 //= 10
        if count != count2:
            return 0
    return 1
