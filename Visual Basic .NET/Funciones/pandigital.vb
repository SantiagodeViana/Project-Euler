'Función usada en Project Euler #032

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
