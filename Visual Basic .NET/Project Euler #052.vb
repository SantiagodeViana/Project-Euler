Module Module1
    Sub Main()
        Dim n As Integer = 2
        Dim n2 As Integer = 1
        Dim product As Integer = Nothing
        Dim same As Integer = Nothing
        Dim peak As Integer = Nothing
        Dim respuesta As Integer = Nothing
        Do
            product = n * n2
            Dim digits1 As String = n.ToString
            Dim digits2 As String = product.ToString
            If digits1.Length = digits2.Length Then 'Substrings, Euler49
                same += 1
            End If
            If n2 > 6 Then
                same = 0 'Números compartidos
                n += 1 'Se buscan más números
                n2 = 1
            End If
            If same > peak And n <> 10 Then
                peak = same
                respuesta = n
            End If
            Console.WriteLine(n & "   " & n2 & "   " & product & "   " & digits1.Length & "   " & digits2.Length & "   " & same & "   " & peak & "   " & respuesta)
            n2 += 1
            'Console.ReadLine()
        Loop
    End Sub
End Module
