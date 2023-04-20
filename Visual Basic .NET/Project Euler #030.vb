Module Module1
    
    ' Solución para el problema #30 de Project Euler
    ' "Encuentra la suma de todos los números que se pueden escribir como suma de quintas potencias de sus dígitos."
    ' https://projecteuler.net/problem=30
    ' Código espagueti de 2016; optimizar

    Function factorial(ByVal number As Long) As Long
        If number <= 1 Then
            Return (1)
        Else
            Return number * factorial(number - 1)
        End If
    End Function

    Sub Main()

        Dim n As Integer = 2
        Dim respuesta As Long = Nothing
        Do
            n += 1
            Dim sum As Long = Nothing
            Dim number As String = n.ToString 'String
            Dim digit() As Char = number.ToCharArray() 'Array de dígitos
            Dim n2 As Integer = Nothing
            Do Until n2 >= digit.Length
                Dim p As Integer = Integer.Parse(digit(n2))
                sum += p ^ 5 'Eleva el dígito a la quinta potencia y súmalos
                n2 += 1
            Loop
            If sum = n Then
                respuesta += n 'Si la suma es igual al número, agrega a la respuesta
            End If
            Console.WriteLine(n & "   " & sum & "   " & respuesta)
            'Console.Read()
        Loop
        Console.WriteLine("La respuesta es " & respuesta) 'La respuesta es 443839
        Console.ReadLine()
    End Sub

End Module
