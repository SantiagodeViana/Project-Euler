Module Module1

    Dim respuesta As Integer = 1
    Dim n As Integer = 1
    Dim move As Integer = Nothing
    Dim limit As Integer = 1000

    'Suma todas las líneas diagonales en un espial de 1001 x 1001
    Function slide()
        n += move
        respuesta = respuesta + n
        Console.WriteLine(n & "   " & move & "  " & respuesta)
    End Function

    Sub Main()

        'Al llegar a la última esquina, terminar
        Do Until move = limit

            n += 1
            move += 1
            n += move
            respuesta = respuesta + n

            Console.WriteLine(n & "   " & move & "  " & respuesta)
            move += 1

            'Suma las esquinas

            slide()
            slide()
            slide()

        Loop

        Console.Write("La respuesta es " & respuesta)
        Console.ReadLine()

    End Sub
End Module