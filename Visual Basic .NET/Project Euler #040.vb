Module Module1
    
    ' Solución para el problema #40 de Project Euler
    ' "Si dn representa la enésima cifra de la parte fraccionaria, encuentra el valor de la siguiente expresión."
    ' https://projecteuler.net/problem=40
    ' Código espagueti de 2016; optimizar
    
    Sub Main()
        Dim n As Integer = Nothing
        Dim position As Integer = Nothing
        Dim dvalue As Integer = Nothing
        Dim limit As Integer = 1
        Dim respuesta As Integer = 1
        Dim digit As String = n.ToString
        Do Until limit > 1000000 'In Champernowne's constant, find the value of the expression d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
            n += 1
            digit = n.ToString
            position += digit.Length 'El número del dígito depende de la cantidad de dígitos de los términos
            If position >= limit Then
                dvalue = Integer.Parse(digit.Substring(digit.Length - (position - limit) - 1, 1)) 'El dígito es la resta de los dígitos sobrantes
                respuesta *= dvalue 'Se multiplican los dígitos
                limit *= 10 'La posición de los dígitos aumenta en base a 10
                Console.WriteLine(n & "   " & position & "   " & respuesta)
            End If
        Loop
        Console.Write("La respuesta es " & respuesta) 'La respuesta es 210
        Console.ReadLine()
    End Sub
End Module
