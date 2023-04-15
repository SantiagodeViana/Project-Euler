Module Module1

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
