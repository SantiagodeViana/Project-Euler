#Código convertido de C con ChatGPT
#Respuesta ofrecida errónea

def main():
    for i in range(1, 50000):
        for j in range(i + 1, 50000):
            if j < 50000 and digit_count(i**3) == digit_count(j**3):
                if (is_permutable(i**3, j**3, digit_count(i**3)) == 1 and
                        is_permutable(j**3, i**3, digit_count(i**3)) == 1):
                    for k in range(j + 1, 50000):
                        if k < 50000 and digit_count(j**3) == digit_count(k**3):
                            if (is_permutable(i**3, k**3, digit_count(j**3)) == 1 and
                                    is_permutable(j**3, k**3, digit_count(j**3)) == 1 and
                                    is_permutable(k**3, j**3, digit_count(j**3)) == 1):
                                for l in range(k + 1, 50000):
                                    if l < 50000 and digit_count(k**3) == digit_count(l**3):
                                        if (is_permutable(i**3, l**3, digit_count(k**3)) == 1 and
                                                is_permutable(j**3, l**3, digit_count(k**3)) == 1 and
                                                is_permutable(k**3, l**3, digit_count(k**3)) == 1 and
                                                is_permutable(l**3, i**3, digit_count(k**3)) == 1 and
                                                is_permutable(l**3, j**3, digit_count(k**3)) == 1 and
                                                is_permutable(l**3, k**3, digit_count(k**3)) == 1):
                                            for m in range(l + 1, 50000):
                                                if m < 50000 and digit_count(l**3) == digit_count(m**3):
                                                    if (is_permutable(i**3, m**3, digit_count(m**3)) == 1 and
                                                            is_permutable(j**3, m**3, digit_count(m**3)) == 1 and
                                                            is_permutable(k**3, m**3, digit_count(m**3)) == 1 and
                                                            is_permutable(l**3, m**3, digit_count(m**3)) == 1 and
                                                            is_permutable(m**3, i**3, digit_count(m**3)) == 1 and
                                                            is_permutable(m**3, j**3, digit_count(m**3)) == 1 and
                                                            is_permutable(m**3, k**3, digit_count(m**3)) == 1 and
                                                            is_permutable(m**3, l**3, digit_count(m**3)) == 1):
                                                        print(f"i: {i}")

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

def digit_count(n):
    count = 0
    i = 1
    while i <= n:
        i *= 10
        count += 1
    return count

if __name__ == "__main__":
    main()
