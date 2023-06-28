Module Module1
    Sub Main()
        Dim base As Integer = 1
        Dim exponent As Integer = 1
        Dim respuesta As Integer = Nothing
        Do
            Dim power As Long = base ^ exponent
            Dim digits As String = power.ToString
            If digits.Length = exponent Then 'Busca los números con la mismo número de dígitos que el exponente
                respuesta += 1
                Console.WriteLine(base & "   " & exponent & "   " & power & "   " & digits & "   " & respuesta)
            End If
            If power > 1000000000000000000 Or base = 1 Then 'Se reinicia cuando el número es muy grande
                base += 1
                exponent = 1
            ElseIf base = 1 Then 'Base incrementa cuando = 1
                base += 1
            Else
                exponent += 1
            End If
            Console.ReadLine() 'La respuesta es 49, overflow cuando 9^(>19)
        Loop
    End Sub
End Module
