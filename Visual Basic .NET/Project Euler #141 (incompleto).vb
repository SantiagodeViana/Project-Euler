Module Module1
    Dim n As Long = Nothing
    Dim respuesta As Long = Nothing
    Function isProgressive(ByVal n As Integer) As Boolean 'Función para determinar si el número es progresivo
        Dim d As Integer = 1
        Do Until d > n
            Dim q As Long = Math.Floor(n / d) 'Quotient
            Dim r As Long = n Mod d 'Reminder
            If d = q Or q = r Or d = r Then 'Si el divisor, el resultado o el residuo son iguales, no es progresivo
                Return False
            ElseIf r = 0 Then 'Si el residuo es nulo, no es progresivo
                Return False
            ElseIf d > q > r Then 'Si el divisor, el resultado y el residuo comparten un common ratio, es progresivo
                If (d / q) = (q / r) Then
                    Return True
                End If
            ElseIf q > d > r Then
                If (q / d) = (d / r) Then
                    Return True
                End If
            ElseIf d > r > q Then
                If (d / r) = (r / q) Then
                    Return True
                End If
            End If
            If isProgressive(n) Then 'Si el número es progresivo y un cuadrado perfecto, sumar a la respuesta
                If Math.Sqrt(n) Mod 1 = 0 Then
                    respuesta += n
                ElseIf Math.Sqrt(d) Mod 1 = 0 Then
                    respuesta += d
                ElseIf Math.Sqrt(q) Mod 1 = 0 Then
                    respuesta += q
                ElseIf Math.Sqrt(r) Mod 1 = 0 Then
                    respuesta += r
                End If
            End If
            Console.Write(n & "   " & d & "   " & q & "   " & r & "   " & isProgressive(n) & "   " & respuesta)
            Console.ReadLine()
        Loop
        Return False
    End Function
    Sub Main()
        Do Until n > 1000000000000 'Consigue la suma de todos los números progresivos que sean cuadrados perfectos menores a un trillón
            isProgressive(n)
            n += 1
            Console.Write(n & "   " & isProgressive(n) & "   " & respuesta)
            Console.ReadLine()
        Loop
        Console.WriteLine("La respuesta es " & respuesta)
        Console.ReadLine()
    End Sub
End Module
