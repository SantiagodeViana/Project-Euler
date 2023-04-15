Module Module1

    'Funcion para determinar si un numero es primo.

    Function isPrime(ByVal n As Integer) As Integer
        If n <= 0 Then
            Return False
        ElseIf n = 1 Then
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

    'Considering quadratics of the form:

    'n² + an + b, where |a| < 1000 and |b| < 1000

    'Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.

    Sub Main()

        Dim n As Integer = Nothing
        Dim a As Integer = -1000
        Dim b As Integer = -1000
        Dim x As Integer = Nothing
        Dim prime As Integer = Nothing
        Dim maxprime As Integer = Nothing
        Dim maxa As Integer = Nothing
        Dim maxb As Integer = Nothing
        Dim respuesta As Integer = Nothing

        Do Until a > 1000

            x = ((n ^ 2) + (a * n) + b)

            If b > 1000 Then
                a += 1
                b = -1000
                Console.WriteLine(n & "   " & a & "   " & b & "   " & x & "   " & prime & "   " & maxprime & "   " & maxa & "   " & maxb & "   " & respuesta)
                n = 0
                prime = 0
            ElseIf isPrime(b) = False Then
                b += 1
                n = 0
                prime = 0
            ElseIf isPrime(x) Then
                n += 1
                prime += 1
            Else
                b += 1
                n = 0
                prime = 0
            End If

            If prime > maxprime Then
                maxprime = prime
                maxa = a
                maxb = b
            End If

            respuesta = maxa * maxb
        Loop
        Console.WriteLine("La respuesta es " & respuesta)
        Console.ReadLine()
    End Sub

End Module
