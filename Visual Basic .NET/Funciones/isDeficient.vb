'Función usada en Project Euler #23

Function isDeficient(ByVal n As Integer) As Boolean 'Función para determinar si el número es deficiente
        If n < 12 And n <> 6 Then
            Return True
        ElseIf isPrime(n) Then
            Return True
        Else
            Dim divisor As Integer = Nothing
            Dim total As Integer = Nothing
            Do While divisor <= (n / 2)
                divisor += 1
                If n Mod divisor = 0 Then
                    total += divisor
                End If
            Loop
            If total < n Then
                Return True
            ElseIf total >= n Then
                Return False
            End If
            Return True
        End If
End Function
