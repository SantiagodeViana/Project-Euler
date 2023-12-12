import math

#Código convertido de C con ChatGPT

def is_prime(n):
    if n == 1:
        return False
    elif n < 4:
        return True
    elif n % 2 == 0:
        return False
    elif n < 9:
        return True
    elif n % 3 == 0:
        return False
    else:
        r = math.floor(math.sqrt(n))
        f = 5
        while f <= r:
            if n % f == 0:
                return False
            elif n % (f + 2) == 0:
                return False
            else:
                f += 6
        return True

def digits(n):
    count = 0
    i = 1
    while i <= n:
        i *= 10
        count += 1
    return count

def digit_sum(n):
    summation = 0
    for i in range(digits(n) + 1):
        summation += n % 10
        n //= 10
    return summation

def is_harshad(n):
    return n % digit_sum(n) == 0

def right_truncatable_harshad(n):
    i = 1
    j = 0
    if n < 10:
        return False
    else:
        while i < n:
            j = n // i
            if not is_harshad(j):
                return False
            i *= 10
    return True

def strong_harshad(n):
    if n % digit_sum(n) != 0:
        return False
    elif n < 10:
        return False
    elif is_prime(n // digit_sum(n)):
        return True
    return False

def right_truncatable_strong_harshad_prime(n):
    if not is_prime(n):
        return False
    elif n < 10:
        return False
    else:
        n //= 10
        if strong_harshad(n) and right_truncatable_harshad(n):
            return True
    return False

respuesta = 0
for i in range(1, 100001):
    if right_truncatable_strong_harshad_prime(i):
        respuesta += i
        print(f"Respuesta: {respuesta} i: {i}")
