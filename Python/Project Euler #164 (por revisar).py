def three_digit_sum(n: int) -> int:
    if n < 100: #Descartando números de menos de 3 dígitos
        return 1
    else:
        sum = 0
        aux2 = n % 10
        n //= 10
        aux = n % 10
        n //= 10
        while n > 0 and sum <= 9:
            sum = (n % 10) + aux + aux2
            aux2 = aux
            aux = n % 10
            n //= 10
    if sum <= 9:
        return 1
    else:
        return 0


def main():
    respuesta = 0
    for n in range(10_000_000_000_000_000_000, 100_000_000_000_000_000_000):
        if three_digit_sum(n) == 1:
            respuesta += 1
        if (n % 1000000 == 0):
            print(f"n: {n}  Respuesta:{respuesta}")
    print(f"La respuesta es: {respuesta}")


if __name__ == "__main__":
    main()
