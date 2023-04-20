'Función usada en Project Euler #30

Function factorial(ByVal number As Long) As Long
    If number <= 1 Then
        Return (1)
    Else
        Return number * factorial(number - 1)
    End If
End Function
