Module Module1

    'Funcion para determinar si un numero es primo.

    Function isPrime(ByVal n As Long) As Boolean
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

    Function pandigital(ByVal input As String) As Boolean 'Función para determinar si el número es pandigital
        Dim number() As Char = input.ToCharArray()
        Dim length As String = (number.Length).ToString
        Dim last As Long = Nothing
        Dim n3 As Long = Nothing
        Do Until last = number.Length - 1
            Do Until n3 = number.Length - 1
                n3 += 1
                If number(last) = number(n3) Then 'No se permiten números repetidos o mayores al número de dígitos para asegurar que sean usados al menos una vez
                    last = 0
                    n3 = 0
                    Return False
                End If
            Loop
            last += 1
            n3 = last
        Loop
        Return True
    End Function

    Sub Main()

        Dim n As Long = 1234567809 'Número pandigital
        Dim n2 As Integer = Nothing 'Número de veces en el que se arrastra el dígito
        Dim n3 As Integer = Nothing 'Número de veces en el que subinteger es divisible
        Dim respuesta As Long = Nothing
        Dim d As Integer = 1

        Do Until n = 5000000000
            n += 1
            If pandigital(n) Then
                d = 0
                n2 = 0
                n3 = 0
                Do Until d = 17
                    d += 1
                    If isPrime(d) Then 'Se dividen los subintegers siete veces entre divisores primos
                        Dim substring As String = n.ToString
                        Dim subinteger As Integer = Integer.Parse(substring.Substring(1 + n2, 1) & substring.Substring(2 + n2, 1) & substring.Substring(3 + n2, 1))
                        n2 += 1
                        If subinteger Mod d = 0 Then
                            n3 += 1
                        End If
                    End If
                Loop
                If n3 = 7 Then 'Si el número es divisible en todas las ocasiones es añadido a la respuesta
                    respuesta += n
                End If
                Console.WriteLine(n & "   " & n2 & "   " & n3 & "   " & d & "   " & respuesta)
            End If
            'Console.WriteLine(n & "   " & n2 & "   " & n3 & "   " & d & "   " & respuesta & "   " & pandigital(n))
        Loop
        Console.WriteLine("La respuesta es " & respuesta) 'La respuesta es 16695334890
        Console.ReadLine() 'La respuesta tarda como 30 minutos/eones en aparecer
    End Sub

End Module
