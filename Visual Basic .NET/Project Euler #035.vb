Module Module1

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
        Dim prime As Integer = Nothing
        Dim respuesta As Integer = Nothing
        Dim circular As String = Nothing
        Dim newcircular As String = Nothing
        Dim circularPrime As Integer = Nothing
        Dim digits() As Char = {"a", "b", "c", "d", "e", "f", "g"}
        Do Until n > 1000000 'Busca la cantidad de primos circulares menores a un millón
            n += 1
            If isPrime(n) Then 'Busca números primos
                prime = n
                circular = prime.ToString
                Dim isCircular As Boolean = True
                Do Until circularPrime = prime 'Voltear el número hasta que vuelva a la posición original (197 --> 971 --> 719 ---> 197)
                    digits(circular.Length - 1) = circular.Substring(circular.Length - 1, 1) 'El primer dígitos será el último
                    newcircular = digits(circular.Length - 1)
                    circularPrime = Integer.Parse(newcircular)
                    If circular.Length > 1 Then 'Cuando el número es mayor de 9, los dígitos cambian de posición de derecha a izquierda
                        n2 = 1
                        Do While n2 < circular.Length
                            digits(n2 - 1) = circular.Substring(n2 - 1, 1)
                            newcircular += digits(n2 - 1)
                            circularPrime = Integer.Parse(newcircular)
                            n2 += 1
                        Loop
                    End If
                    If isPrime(circularPrime) = False Then
                        isCircular = False
                    End If
                    circular = newcircular
                Loop
                If isCircular = True Then
                    respuesta += 1
                    Console.WriteLine(prime & "   " & circularPrime & "   " & n2 & "   " & newcircular & "   " & respuesta & "   " & isCircular)
                    'Console.ReadLine()
                End If
                newcircular = Nothing
            End If
        Loop
        Console.WriteLine("La respuesta es " & respuesta) 'La respuesta es 55
        Console.ReadLine()
    End Sub
End Module
