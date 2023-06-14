Module Module1

    Sub Main()

        'Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

        Dim base As Integer = 0
        Dim suma As Long = 0

        Do Until base <= 1000

            base += 1
            suma += base ^ base

            'Cuando base aproxima a 20, el programa se detiene por desbordamiento
            'Busca una alternativa

        Loop

        Console.Write(base)
        Console.Write(" ")
        Console.WriteLine(suma)
        Console.ReadLine()

    End Sub

End Module
