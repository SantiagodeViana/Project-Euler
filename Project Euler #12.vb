Module Module1

    Sub Main()
        ' Solución para el problema #12 de Project Euler
        ' "¿Cuál es el valor del primer número triangular que tiene más de quinientos divisores?"
        ' https://projecteuler.net/problem=12
        ' Código espagueti de 2016; optimizar
    
        'Encuentra el primer número triangular con más de quinientos (500) divisores

        Dim n As Integer = Nothing 'Número de divisores
        Dim cuenta As Integer = Nothing 'Último número de divisores
        Dim respuesta As Integer = Nothing
        Dim divisor As Integer = Nothing
        Dim base As Integer = 2
        Dim limite As Integer = 500

        Do Until cuenta > limite

            divisor += 1

            'Cuenta divisor
            If respuesta Mod divisor = 0 Then
                n += 1
            End If

            'Se prosigue al próximo número triangular
            If divisor > respuesta Then
                n += 1
                respuesta += base
                base += 1
                cuenta = n
                divisor = 1
                n = 0
            End If

            'If cuenta >= 200 Then
            Console.WriteLine(n & "   " & cuenta & "   " & respuesta & "   " & divisor)
            'End If

        Loop

        Console.Write("La respuesta es " & respuesta)
        Console.ReadLine()

        'El programa tardó toda una noche en conseguir la respuesta, más de una hora. Optimizar
        'La respuesta es 76576500

        'Update 06/04/16: Programa un poco mejor redactado, puede que el resultado sea diferente
        'No tengo ni idea de qué fue lo que programé

    End Sub

End Module
