Module Module1
    
    ' Solución para el problema #23 de Project Euler
    ' "¿Cuál es el total de todas las puntuaciones de nombres del archivo?"
    ' https://projecteuler.net/problem=23
    ' Código espagueti de 2016; optimizar

    Function isPrime(ByVal n As Integer) As Boolean 'Función para determinar si un numero es primo.
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
    Function isAbundant(ByVal n As Integer) As Boolean 'Función para determinar si el número es abundante
        If n < 12 Then
            Return False
        ElseIf isPrime(n) Then
            Return False
        Else
            Dim divisor As Integer = Nothing
            Dim total As Integer = Nothing
            Do While divisor <= (n / 2)
                divisor += 1
                If n Mod divisor = 0 Then
                    total += divisor
                End If
            Loop
            If total > n Then
                Return True
            ElseIf total <= n Then
                Return False
            End If
            Return True
        End If
    End Function
    Function isDeficient(ByVal n As Integer) As Boolean 'Función para determinar si el número es deficiente
        If n < 12 And n <> 6 Then
            Return True
        ElseIf isPrime(n) Then
            Return True
        Else
            Dim divisor As Integer = Nothing
            Dim total As Integer = Nothing
            Do While divisor <= (n / 2)
                divisor += 1
                If n Mod divisor = 0 Then
                    total += divisor
                End If
            Loop
            If total < n Then
                Return True
            ElseIf total >= n Then
                Return False
            End If
            Return True
        End If
    End Function
    Function isPerfect(ByVal n As Integer) As Boolean 'Función para determinar si el número es perfecto
        If n = 6 Then
            Return True
        End If
        If n < 12 Then
            Return False
        ElseIf isPrime(n) Then
            Return False
        Else
            Dim divisor As Integer = Nothing
            Dim total As Integer = Nothing
            Do While divisor <= (n / 2)
                divisor += 1
                If n Mod divisor = 0 Then
                    total += divisor
                End If
            Loop
            If total = n Then
                Return True
            Else
                Return False
            End If
            Return True
        End If
    End Function

    Sub Main()
        Dim respuesta As Integer = Nothing
        Dim n As Integer = Nothing
        Dim n2 As Integer = Nothing
        Dim n3 As Integer = Nothing
        Do Until n2 > (28123 / 2) + 1
            Do Until isAbundant(n3)
                n3 += 1
            Loop
            If (n2 + n3) > (28123 / 2) + 1 Then
                n2 += 1
                Do Until isAbundant(n2)
                    n2 += 1
                Loop
                n3 = n2
            ElseIf isAbundant(n2) And isAbundant(n3) Then
                respuesta += (n2 + n3)
            End If
            Console.WriteLine(n & "   " & n2 & "   " & n3 & "   " & respuesta)
            'Console.ReadLine()
            n3 += 1
        Loop
        Console.WriteLine("La respuesta es " & respuesta) 'Idk what I'm doing wrong
        Console.ReadLine()
    End Sub
End Module
