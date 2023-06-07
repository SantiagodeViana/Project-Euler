Module Module1
    Sub Main()
        
        ' Solución para el problema #45 de Project Euler
        ' "Encuentra el siguiente número triangular que también sea pentagonal y hexagonal."
        ' https://projecteuler.net/problem=45
        ' Código de 2016; optimizar

        'El programa busca el próximo número triangular después de 40755 que también sea pentagonal y hexagonal

        Dim triangular As Boolean = False
        Dim pentagonal As Boolean = False
        Dim hexagonal As Boolean = False
        Dim n As Long = 40755

        'El programa usa las fórmulas reversas para comprobar si el número tiene alguna de estas propiedades
        'Si es un íntegro, sin decimales, entonces es triangular, pentagonal o hexagonal
        
        Do Until triangular And pentagonal And hexagonal = True
            n += 1
            triangular = ((0.5 * Math.Sqrt(8 * n + 1)) - 0.5) Mod 1 = 0
            pentagonal = ((Math.Sqrt(24 * n + 1) + 1) / 6) Mod 1 = 0
            hexagonal = ((Math.Sqrt(8 * n + 1) + 1) / 4) Mod 1 = 0
            If n Mod 5000000 = 0 Then 'Se imprime n cada cinco millones de veces para ver el progreso del programa
                Console.WriteLine(triangular & "    " & pentagonal & "    " & hexagonal & "    " & n)
            End If
        Loop
        'El programa se detiene una vez encontrado el número
        Console.WriteLine("La respuesta es " & n)
        Console.ReadLine()
        'La respuesta es 1533776805
    End Sub

End Module
