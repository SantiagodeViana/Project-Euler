Module Module1
    
    ' Solución para el problema #38 de Project Euler
    ' "¿Cuál es el mayor número pandigital de 9 cifras que puede formarse como producto concatenado de un número entero con (1,2, ... , n) donde n > 1?"
    ' https://projecteuler.net/problem=38
    ' Código espagueti de 2016; optimizar

    Function pandigital(ByVal input As String) As Boolean 'Función para determinar si el número es pandigital
        Dim number() As Char = input.ToCharArray()
        Dim length As String = (number.Length).ToString
        Dim last As Long = Nothing
        Dim n3 As Long = Nothing
        Do Until last = number.Length - 1
            Do Until n3 = number.Length - 1
                n3 += 1
                If number(last) = number(n3) Or number(n3) = "0" Or number(last) > length Or number(n3) > length Then 'No se permiten números repetidos o mayores al número de dígitos para asegurar que sean usados al menos una vez
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
    Dim n As Integer = 1
    Dim n2 As Integer = 1
    Dim product As String = Nothing
    Dim digits As Integer = Nothing
    Dim total As String = Nothing
    Dim respuesta As Integer = Nothing

    Sub Main()
        Do Until n > 10000
            product = (n * n2).ToString()
            total += product
            digits = total.Length
            If digits < 9 Then
                n2 += 1
            ElseIf digits = 9 And pandigital(total) Then
                If total > respuesta Then
                    respuesta = total
                End If
            ElseIf digits > 9 Or pandigital(total) = False Then
                n += 1
                n2 = 1
                total = Nothing
            End If
            Console.WriteLine(n & "   " & n2 & "   " & digits & "   " & total & "   " & respuesta)
            'Console.ReadLine()
        Loop
        Console.Write("La respuesta es " & respuesta)
        Console.ReadLine()
    End Sub
End Module
