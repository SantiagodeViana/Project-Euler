Module Module1

    Sub Main()
        ' Solución para el problema #18 de Project Euler
        ' "Halla la suma total máxima de arriba a abajo del triángulo de abajo:"
        ' https://projecteuler.net/problem=18
        ' Código espagueti de 2016; optimizar

        Dim triangle = New Integer(14, 14) {{75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {20, 4, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {19, 1, 23, 75, 3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {88, 2, 77, 73, 7, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0}, {99, 65, 4, 28, 6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0}, {41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0}, {41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0}, {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0}, {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0}, {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0}, {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0}, {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}}
        Dim y As Integer = Nothing
        Dim x As Integer = Nothing
        Dim next1 As Integer = Nothing
        Dim next2 As Integer = Nothing
        Dim respuesta As Integer = Nothing

        Do Until y > 14

            respuesta += triangle(y, x)

            'Determina cuál es la mayor suma en los dos siguientes escalones
            If y < 14 Then
                y += 1
                If y < 13 Then
                    If triangle(y + 1, x) > triangle(y + 1, x + 1) Then
                        next1 = triangle(y + 1, x)
                    ElseIf triangle(y + 1, x) < triangle(y + 1, x + 1) Then
                        next1 = triangle(y + 1, x + 1)
                    End If

                    If triangle(y + 1, x + 1) > triangle(y + 1, x + 2) Then
                        next2 = triangle(y + 1, x + 1)
                    ElseIf triangle(y + 1, x + 1) < triangle(y + 1, x + 2) Then
                        next2 = triangle(y + 1, x + 2)
                    End If
                End If
            End If

            If triangle(y, x) + next1 < triangle(y, x + 1) + next2 Then
                x += 1
            End If

            Console.Write(respuesta & "   " & x & "   " & y & "   " & triangle(y, x))
            Console.ReadLine()

            If y = 14 Then
                respuesta += triangle(y, x)
                y += 1
            End If
        Loop

        Console.WriteLine("La respuesta es " & respuesta)
        Console.ReadLine()
    End Sub
End Module
