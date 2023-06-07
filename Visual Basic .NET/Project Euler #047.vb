Module Module1
  
  ' Solución para el problema #47 de Project Euler
  ' "Encuentra los cuatro primeros números enteros consecutivos que tienen cuatro factores primos distintos cada uno. ¿Cuál es el primero de estos números?"
  ' https://projecteuler.net/problem=47
  ' Código de 2016; optimizar

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

        Dim n As Integer = Nothing
        Dim factor As Integer = 2
        Dim last_factor As Integer = Nothing
        Dim counter As Integer = Nothing
        Dim consecutive As Integer = Nothing
        Dim respuesta As Integer = Nothing
        Dim limite As Integer = 4

        'Encuentra cuatro números consecutivos con cuatro factores primos distintos
        Do Until consecutive = limite

            n += 1
            counter = 0
            respuesta = n

            'Descompone
            Do Until n = 1
                If isPrime(factor) And n Mod factor = 0 Then
                    n = n / factor
                    If last_factor <> factor Then
                        counter += 1
                        last_factor = factor
                    End If
                ElseIf n Mod factor <> 0 Then
                    factor += 1
                End If
            Loop

            factor = 2

            'Si se alcanza el número de factores, se agrega el número a la secuencia
            If counter = limite Then
                consecutive += 1
                'Si no es consecutivo, se empieza de nuevo
            Else
                consecutive = 0
            End If
            n = respuesta
        Loop

        Console.WriteLine("La respuesta es " & respuesta - (limite - 1))
        Console.ReadLine()

    End Sub

End Module
