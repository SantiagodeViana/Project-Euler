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

        Dim n As Integer = 1
        Dim primo1 As Integer = 2
        Dim primo2 As Long = 2
        Dim primo3 As Long = 2
        Dim primomin As Long = 2
        Dim primomin2 As Long = 2
        Dim suma As Long = 0
        Dim limite As Integer = 50000000
        Dim respuesta As Integer = 0

        'Busca cuántos números menores a cincuenta millones pueden expresarse como la suma de una cuadrado, un cubo y un fourth power primos

        Do Until primo2 ^ 3 > limite And primo3 ^ 4 > limite

            'Cuando se encuentre un primo, se suma a la respuesta

            If isPrime(n) Then
                primo1 = n
                suma = primo1 ^ 2 + primo2 ^ 3 + primo3 ^ 4
                If suma <= limite Then
                    respuesta += 1
                End If
            End If

            n += 1

            'Si el cubo es mayor al límite pero el fourt power entonces se repite el proceso
            If primo2 ^ 3 > limite And limite > primo3 ^ 4 Then

                Console.Write(n)
                Console.Write("   ")
                Console.Write(respuesta)
                Console.Write("   ")
                Console.Write(primo1 ^ 2)
                Console.Write("   ")
                Console.Write(primo2 ^ 3)
                Console.Write("   ")
                Console.Write(primo3 ^ 4)
                Console.Write("   ")
                Console.Write(suma)
                Console.Write("   ")
                Console.Write(primomin)
                Console.Write("   ")
                Console.WriteLine(primomin2)
                'Console.ReadLine()

                n = 2
                primo1 = 2
                primo2 = 2 'La base del cubo vuelve al siguiente primo
                primo3 = primomin2 'La base del fourth power vuelve al siguiente primo
                primomin = 2 'La base del fourth power será menor que la del cubo

                Do Until primo3 > primomin2 And isPrime(primo3)
                    primo3 = primo3 + 1
                Loop
                primomin2 = primo3 'Se consigue el próximo primo para repetir el proceso

            ElseIf suma > limite And limite > primo2 ^ 3 Then  'Cuando la suma es mayor que el límite pero el cubo es menor al límite
                primo1 = 2 'La base del cuadrado regresa a 2, el menor primo
                n = 2 'Se vuelven a buscar primos desde 3
                primo2 = primomin 'La base del cubo vuelve al siguiente primo
                Do Until primo2 > primomin And isPrime(primo2)
                    primo2 = primo2 + 1
                Loop
                primomin = primo2 'Se escoge una nueva base prima

            ElseIf suma > limite And suma < primo2 ^ 3 Then
                primo1 = 2
                primo2 = 2
            End If
        Loop

        Console.Write("La respuesta es ")
        Console.Write(respuesta)
        Console.ReadLine()

    End Sub
End Module
