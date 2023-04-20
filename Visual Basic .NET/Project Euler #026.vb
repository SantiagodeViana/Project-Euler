Module Module1

    ' Solución para el problema #26 de Project Euler
    ' "Encuentra el valor de d < 1000 para el que 1/d contiene el ciclo recurrente más largo en su parte de fracción decimal."
    ' https://projecteuler.net/problem=26
    ' Código espagueti de 2016; optimizar
    
    Sub Main()

        Dim n As Integer = 2
        Dim fraction As Double = (1 / n) * 10 ^ 16

        Do Until n > 1000

            'Intentar con números primos
            'Evitar overload

            fraction = (1 / n) * 10 ^ 15
            Console.Write(fraction)
            Console.Write("    ")
            Console.Write(n)
            Console.ReadLine()
            n = n + 1

        Loop

    End Sub

End Module
