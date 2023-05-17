Module Module1
  
    ' Solución para el problema #41 de Project Euler
    ' "¿Cuál es el mayor primo pandigital de n dígitos que existe?"
    ' https://projecteuler.net/problem=41
    ' Código espagueti de 2016; optimizar
  
    Function isPrime(ByVal n As Long) As Boolean 'Funcion para determinar si un numero es primo.
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
                If number(last) = number(n3) Or number(n3) = "0" Then  'No se permiten números repetidos o mayores al número de dígitos para asegurar que sean usados al menos una vez
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
        Dim n As Long = 1
        Dim respuesta As Long = Nothing
        Do Until n > 100000000
            n += 3
            If pandigital(n) = True And isPrime(n) = True Then
                respuesta = n
                Console.WriteLine(respuesta & "   " & isPrime(n))
            End If
        Loop
        Console.Write("La respuesta es " & respuesta)
        Console.ReadLine() 'La respuesta es 7652413
    End Sub
End Module
