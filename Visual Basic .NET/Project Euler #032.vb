Module Module1
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
    Dim multiplicand As String = Nothing
    Dim multiplier As String = Nothing
    Dim product As String = Nothing
    Dim digits As Integer = Nothing
    Dim total As String = Nothing
    Dim respuesta As Integer = Nothing
    Dim answers As Integer = Nothing

    Sub Main()
        Do Until multiplier = 10000
            multiplicand = n.ToString()
            multiplier = n2.ToString()
            product = (multiplicand * multiplier).ToString()
            digits = multiplicand.Length + multiplier.Length + product.Length
            total = multiplicand + multiplier + product
            If digits < 9 Then
                n += 1
            ElseIf digits > 9 Then
                n = 1
                n2 += 1
            End If
            If digits = 9 Then
                pandigital(total)
                If pandigital(total) Then
                    respuesta += product
                    answers += 1
                    Console.WriteLine(answers & "   " & multiplicand & "   " & multiplier & "   " & product & "   " & digits & "   " & total & "   " & respuesta)
                    'Console.ReadLine()
                End If
                n += 1
            End If
        Loop
        respuesta /= 2 'Se eliminan los productos repetidos
        Console.Write("La respuesta es " & respuesta) 'La respuesta es 45228
        Console.ReadLine() '5346 y 5796 se repiten una vez más
    End Sub
End Module
