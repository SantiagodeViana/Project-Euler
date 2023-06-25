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
        Dim n As Integer = 1
        Dim prime1 As Integer = 1009
        Dim prime2 As Integer = prime1 + n
        Dim prime3 As Integer = prime2 + n
        Dim permutation As Boolean = Nothing
        Dim repeated As Boolean = Nothing
        Do Until permutation = True
            n += 2
            prime2 = prime1 + n
            prime3 = prime2 + n
            If prime3 >= 10000 Then
                prime1 += 1
                Do Until isPrime(prime1) 'Buscar números primos
                    prime1 += 1
                    n = 2
                Loop
            ElseIf isPrime(prime1) And isPrime(prime2) And isPrime(prime3) Then 'La secuencia aritmética debe producir tres números primos
                Dim digits1 As String = prime1.ToString
                Dim digits2 As String = prime2.ToString
                Dim digits3 As String = prime3.ToString
                Dim n2 As Integer = Nothing
                Dim n3 As Integer = Nothing
                repeated = False
                n2 = 0
                n3 = 1
                Do Until repeated = True Or n2 > 3 'Si el número repite dígitos entonces no es permutable (hay que quitar esto y arreglarlo
                    If n3 > 3 Then
                        n3 = n2 + 2
                        n2 += 1
                    ElseIf digits1.Substring(n2, 1) = digits1.Substring(n3, 1) Or digits2.Substring(n2, 1) = digits2.Substring(n3, 1) Or digits3.Substring(n2, 1) = digits3.Substring(n3, 1) Or prime1 = 1487 Then
                        repeated = True
                    Else
                        n3 += 1
                    End If
                Loop
                n2 = 0
                n3 = 0
                Do Until permutation <> False Or n3 > 3 Or repeated = True 'Demuestra si los números son permutaciones
                    Console.WriteLine(n2 & "   " & digits1.Substring(n2, 1) & "   " & digits2.Substring(n3, 1) & "   " & permutation)
                    'Console.ReadLine()
                    If n2 = 3 And digits1.Substring(n2, 1) = digits2.Substring(n3, 1) Then
                        n2 = 0
                        n3 = 0
                        Do Until permutation <> Nothing Or n3 > 3
                            If n2 = 3 And digits2.Substring(n2, 1) = digits3.Substring(n3, 1) Then
                                permutation = True
                            ElseIf digits2.Substring(n2, 1) = digits3.Substring(n3, 1) Then
                                n2 += 1
                                n3 = 0
                            Else
                                n3 += 1
                            End If
                        Loop
                    ElseIf digits1.Substring(n2, 1) = digits2.Substring(n3, 1) Then
                        n2 += 1
                        n3 = 0
                    Else
                        n3 += 1
                    End If
                Loop
                Console.WriteLine(n & "   " & prime1 & "   " & prime2 & "   " & prime3 & "   " & permutation & "   " & repeated)
                'Console.ReadLine()
            End If
        Loop
        Console.WriteLine("La respuesta es " & prime1 & prime2 & prime3) '¿Y si se permuta un número primo para crear dos primos más, y se comprueba si la diferencia entre los tres es la misma?
        Console.ReadLine()
    End Sub
End Module
