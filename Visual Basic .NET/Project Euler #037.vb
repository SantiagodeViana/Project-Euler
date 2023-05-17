Module Module1
    
    ' Solución para el problema #37 de Project Euler
    ' "Encuentra la suma de los once únicos números primos que son truncables de izquierda a derecha y de derecha a izquierda a la vez"
    ' https://projecteuler.net/problem=37
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
    Sub Main()

        Dim n As Integer = Nothing
        Dim n2 As Integer = Nothing
        Dim digits() As Char = {"0", "0", "0", "0", "0", "0", "0", "0", "0"}
        Do
            n += 1
            If isPrime(n) And n > 9 Then
                Dim trucatable As Integer = n
                Dim prime As String = n.ToString
                Dim isTrucatable As Boolean = True
                digits = prime.ToCharArray()
                n2 = 0
                prime = Nothing
                Do Until trucatable < 9 Or isTrucatable = False
                    digits(n2) = Nothing
                    Do Until digits(n2) = Nothing
                        prime += digits(n2)
                        n2 += 1
                    Loop
                    Do Until digits(n2) = Nothing
                        n -= 1
                    Loop
                    n2 -= 1
                    trucatable = Integer.Parse(prime)
                    If isPrime(trucatable) = False Then
                        isTrucatable = False
                    End If
                    Console.Write(n & "   " & trucatable)
                    Console.ReadLine()
                    n2 += 1
                Loop
                digits = prime.ToCharArray()
                prime = Nothing
                n2 = 1
                Do Until trucatable < 9 Or isTrucatable = False
                    digits(digits.Length - n2) = Nothing
                    'trucatable = Integer.Parse(digits(0) & digits(1) & digits(2) & digits(3) & digits(4) & digits(5) & digits(6) & digits(7) & digits(8))
                    If isPrime(trucatable) = False Then
                        isTrucatable = False
                    End If
                    n2 += 1
                Loop
                Dim respuesta = Nothing
                If isPrime(trucatable) And trucatable < 9 Then
                    respuesta += n
                    Console.Write(n & "   " & trucatable & "   " & respuesta)
                    Console.ReadLine()
                End If
            End If
        Loop

    End Sub
End Module
