Module Module1
    '  Solución para el problema #5 de Project Euler
    ' "¿Cuál es el menor número positivo divisible por todos los números del 1 al 20?"
    ' https://projecteuler.net/problem=5
    ' Código espagueti de 2015, optimizar

    Sub Main()

        Dim residuo As Integer = 0
        Dim divisor As Integer = 2
        Dim dividendo As Integer = 2520
        Dim limite As Integer = 20
        Dim respuesta As Boolean = False

        Do
            residuo = dividendo Mod divisor

            'Busca un número divisible entre todos los números dentro del límite (en este caso 20), contando de 2520
            '2520 es el menor número divisible en el límite de 10. Estos números parecen ser todos múltiples o factores de sí mismos

            If residuo <> 0 Then
                dividendo += 2520
            ElseIf residuo = 0 Then
                divisor += 1
            End If

            'Si se supera el límite, se repite el proceso

            If divisor > limite Then
                divisor = 2
            End If

        Loop

        'La respuesta es 232792560

        Console.Write("La respuesta es ")
        Console.Write(dividendo)
        Console.ReadLine()

        'Mejoras:
        'Para limite = 20, la respuesta se consigue en 20 segundos. 
        'El algoritmo tiene que ser mejorado para que el dividendo incremente cada vez que se consiga un múltiplo
        '¿Sumar mcd anterior? 

    End Sub

End Module
