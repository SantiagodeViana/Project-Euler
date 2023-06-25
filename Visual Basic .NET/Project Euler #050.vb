Module Module1  
    
    Function isPrime(ByVal n As Integer) As Integer 'Función para determinar si un número es primo.
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
    Sub Main()
        Dim secuencia As Integer = 1
        Dim secuenciamax As Integer = 1
        Dim respuesta As Integer = 1
        Dim primo As Integer = 3
        Dim primomin As Integer = 3
        Dim suma As Long = 2
        Dim limite As Integer = 1000000
        'Encuentra la suma prima más larga de primos consecutivos menor a un millón.
        Do Until primomin > limite / 2
            'Busca números primos; si es primo, se incluye a la suma y se alarga la secuencia.
            If isPrime(primo) Then
                suma += primo
                secuencia += 1
            End If
            primo = primo + 2
            'Si la suma es prima y la secuencia es la más larga hasta ahora.
            If isPrime(suma) And secuenciamax < secuencia Then
                secuenciamax = secuencia
                respuesta = suma
                Console.Write(primo & "   " & suma & "   " & secuencia & "   " & secuenciamax & "   " & respuesta)
            End If
            'Cuando la suma supere el límite (un millón), se reinicia el proceso empezando por un primo mayor.
            'Ej: Cuando se termina la secuencia empezando por 3, se comienza una comenzando por 5.
            If suma > limite Then
                suma = primomin
                secuencia = 1
                primo = primomin
                Do Until primo > primomin And isPrime(primo)
                    primo = primo + 2
                Loop
                primomin = primo
            End If
        Loop
        'Imprime respuesta.
        Console.Write("La respuesta es " & respuesta)
        Console.ReadLine()
    End Sub
End Module
