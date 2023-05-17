Module Module1
    
    ' Solución para el problema #34 de Project Euler
    ' "Encuentra la suma de todos los números que son iguales a la suma del factorial de sus cifras."
    ' https://projecteuler.net/problem=34
    ' Código espagueti de 2016; optimizar

    Function factorial(ByVal number As Long) As Long
        If number <= 1 Then
            Return (1)
        Else
            Return number * factorial(number - 1)
        End If
    End Function

    Sub Main()

        Dim n As Integer = 11
        Dim respuesta As Long = Nothing
        Do Until respuesta = 40730
            n += 1
            Dim sum As Long = Nothing
            Dim number As String = n.ToString 'String
            Dim digit() As Char = number.ToCharArray() 'Dígitos
            Dim n2 As Integer = Nothing
            Do Until n2 >= digit.Length
                Dim f As Integer = Integer.Parse(digit(n2)) 'Factorial del dígito
                sum += factorial(f) 'Suma de los factoriales
                n2 += 1
            Loop
            If sum = n Then 'Si la suma es igual al número, añade a respuesta
                respuesta += n
            End If
            Console.WriteLine(n & "   " & sum & "   " & respuesta)
        Loop
        Console.WriteLine("La respuesta es " & respuesta) 'La respuesta es 40730
        Console.ReadLine()
    End Sub

End Module
