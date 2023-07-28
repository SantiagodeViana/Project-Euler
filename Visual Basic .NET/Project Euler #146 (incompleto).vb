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

        Dim n As Integer = 1
        Dim prime1 As Integer = Nothing
        Dim prime2 As Integer = Nothing
        Dim prime3 As Integer = Nothing
        Dim prime4 As Integer = Nothing
        Dim prime5 As Integer = Nothing
        Dim prime6 As Integer = Nothing
        Dim respuesta As Long = prime1 + prime2 + prime3 + prime4 + prime5 + prime6

        'Busca la suma de los primos cuando sean consecutivos

        Do Until isPrime(prime1) And isPrime(prime2) And isPrime(prime3) And isPrime(prime4) And isPrime(prime5) And isPrime(prime6)

            prime1 = n ^ 2 + 1
            prime2 = n ^ 2 + 3
            prime3 = n ^ 2 + 7
            prime4 = n ^ 2 + 9
            prime5 = n ^ 2 + 13
            prime6 = n ^ 2 + 27
            respuesta = prime1 + prime2 + prime3 + prime4 + prime5 + prime6
            n += 1

            Console.WriteLine(n)
        Loop

        Console.Write("La respuesta es ")
        Console.Write(respuesta)
        Console.ReadLine()

    End Sub

End Module
