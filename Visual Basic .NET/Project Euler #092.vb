Module Module1
    Sub Main()
        Dim n As Integer = Nothing
        Dim square As Integer = Nothing
        Dim respuesta As Integer = Nothing
        Do Until n = 10000000
            n += 1
            Dim digits As String = n.ToString
            Dim digitvalue() As Char = digits.ToCharArray
            square = Nothing
            Do Until square = 89 Or square = 1 'Detener cuando se termina la secuencia o se repite
                Dim n2 As Integer = Nothing
                square = Nothing
                Do Until n2 = digitvalue.Length
                    square += (Integer.Parse(digitvalue(n2))) ^ 2 'Sumar el cuadrado de los dígitos
                    n2 += 1
                Loop
                digits = square.ToString
                digitvalue = digits.ToCharArray
                If square = 89 Then 'Suma a la respuesta aquellas secuencias que se repiten
                    respuesta += 1
                End If
            Loop
            Console.WriteLine(n & "   " & square & "   " & respuesta)
            'Console.ReadLine()
        Loop
        Console.Write("La respuesta es " & respuesta) 'La respuesta es 8581146
        Console.ReadLine()
    End Sub
End Module
