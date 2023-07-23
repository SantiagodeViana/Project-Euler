Module Module1

    'Funcion para determinar si un numero es primo.

    Function isPrime(ByVal n As Integer) As Integer
        If n = 1 Then
            Return False
        ElseIf n < 4 Then
            Return True
        ElseIf n Mod 2 = 0 Then
            Return False
        ElseIf n < 9 Then
            Return True
        ElseIf n Mod 3 = 0 Then
            Return False
        Else
            Dim r As Integer = Math.Floor(Math.Sqrt(n))
            Dim f As Integer = 5
            Do While f <= r
                If n Mod f = 0 Then
                    Return False
                ElseIf n Mod (f + 2) = 0 Then
                    Return False
                Else
                    f += 6
                End If
            Loop
            Return True
        End If
    End Function

    Sub Main()

        Dim x As Long = 2
        Dim D As Long = 3
        Dim y As Long = 1
        Dim n As Integer = 1
        Dim limite As Integer = 1000
        Dim resultado As Integer = 1
        Dim solution As Integer = 0
        Dim maxsolution As Long = 0
        Dim respuesta As Integer = 0

        Do Until D > limite

            resultado = (x ^ 2) - (D * y ^ 2) '¿Buscar manera de simplificar la ecuación?
            '¿D es primo?

            'Cuando el resultado sea negativo, incrementa x

            If resultado < 0 Then
                x += 1
            End If

            'Cuando el resultado sea mayor que 1, incrementa x

            If resultado > 0 Then
                y += 1
            End If

            'Cuando el resultado sea 1, se reinicia la búsqueda
            'D aumenta por uno

            If resultado = 1 Then
                solution = x
                If solution > maxsolution Then
                    respuesta = D 'La respuesta es D cuando x esté en su valor más alto
                    maxsolution = solution
                End If
                Console.Write("x: ")
                Console.Write(x)
                Console.Write("  D: ")
                Console.Write(D)
                Console.Write("  y: ")
                Console.Write(y)
                Console.Write("  = ")
                Console.Write(resultado)
                Console.Write("   ")
                Console.Write(solution)
                Console.Write("   ")
                Console.WriteLine(respuesta)
                'Console.ReadLine()
                x = 2
                y = 1
                n = 1
                Do Until n > D And isPrime(n)
                    n += 2
                Loop
                D = n
            ElseIf resultado = 0 Then 'Si el resultado es 0, no se puede encontrar 1
                Console.Write("x: ")
                Console.Write(x)
                Console.Write("  D: ")
                Console.Write(D)
                Console.Write("  y: ")
                Console.Write(y)
                Console.Write("  = ")
                Console.Write(resultado)
                Console.Write("   ")
                Console.Write(solution)
                Console.Write("   ")
                Console.WriteLine(respuesta)
                Console.ReadLine()

                x = 2
                y = 1
                Do Until n > D And isPrime(n) 'Por lo tanto, se continúa el proceso
                    n += 2
                Loop
                D = n
            End If
           
        Loop

        Console.Write("La respuesta es ")
        Console.Write(respuesta)
        Console.ReadLine()

    End Sub

End Module
