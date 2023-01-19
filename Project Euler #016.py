def sum_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s

x = 2**1000
print x
print sum_digits(x)
