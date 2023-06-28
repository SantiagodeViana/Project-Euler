Module Module1     
    Function isPrime(ByVal n As Integer) As Integer 'Funcion para determinar si un numero es primo.
        If n = 1 Then
            Return False
        ElseIf n < 4 Then
            Return True
        ElseIf n Mod 2 = 0 Then
            Return False
        ElseIf n < 9 Then
            Return True
        ElseIf n Mod 3 = 0 Then
            Return False
        Else
            Dim r As Integer = Math.Floor(Math.Sqrt(n))
            Dim f As Integer = 5
            Do While f <= r
                If n Mod f = 0 Then
                    Return False
                ElseIf n Mod (f + 2) = 0 Then
                    Return False
                Else
                    f += 6
                End If
            Loop
            Return True
        End If
    End Function
    Dim n As Integer = 1
    Dim move As Integer = Nothing
    Dim prime As Integer = Nothing
    Dim total As Integer = Nothing
    Dim porcentaje As Decimal = 100
    Dim respuesta As Integer = 1
    'Suma todas las líneas diagonales en un espiral de 1001 x 1001
    Function slide()
        n += move
        If isPrime(n) Then
            prime += 1
            total += 1
        Else
            total += 1
        End If
        porcentaje = (prime / total) * 100
        Console.WriteLine(n & "   " & prime & "  " & total & "  " & porcentaje & "  " & respuesta)
        'Console.ReadLine()
        Return True
    End Function
    Sub Main()
        'Al llegar a la última esquina, terminar
        Do Until porcentaje < 10
            n += 1
            move += 1
            n += move
            If isPrime(n) Then
                prime += 1
                total += 1
            Else
                total += 1
            End If
            porcentaje = (prime / total) * 100
            move += 1
            'Suma las esquinas
            slide()
            slide()
            slide()
            respuesta += 2
            porcentaje = (prime / total) * 100
        Loop
        Console.Write("La respuesta es " & respuesta - 2) 'La respuesta es 26241
        Console.ReadLine()
    End Sub
End Module
