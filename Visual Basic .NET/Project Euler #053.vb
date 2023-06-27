Module Module1
    Function factorial(ByVal n As Integer) As Long 'Función para un factorial (n!)
        If n <= 1 Then
            Return 1
        Else
            Return factorial(n - 1) * n
        End If
    End Function
    Sub Main()
        Dim n As Integer = Nothing
        Dim r As Integer = Nothing
        Dim c As Integer = Nothing
        Do Until c > 1000000
            If r < n Then
                r += 1
            ElseIf r >= n Then
                n += 1
                r = 2
            End If
            c = (factorial(n) / (factorial(r) * factorial(n - r)))
            Console.WriteLine(n & "   " & r & "   " & c)
            'Console.ReadLine()
        Loop
        Console.WriteLine("La respuesta es " & n) 'Overflow when n = 21 (21! > 1E+18)
        Console.ReadLine()
    End Sub
End Module
