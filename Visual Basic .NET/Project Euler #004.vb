Module Module1
    ' Solución para el problema #4 de Project Euler
    ' "Encuentra el palíndromo más grande formado por el producto de dos números de 3 cifras."
    ' https://projecteuler.net/problem=4   
    ' Código espagueti de 2015; considerar optimización

    Sub Main()

        'Este programa busca el mayor palíndromo (se pueda leer igual de ambos lados) que se puede conseguir entre el producto de dos números de tres dígitos

        Dim cuenta As Integer = 0
        Dim producto1 As Integer = 1000
        Dim producto2 As Integer = 999
        Dim num1 As Integer = 1
        Dim num2 As Integer = 2
        Dim num3 As Integer = 8
        Dim num4 As Integer = 4
        Dim num5 As Integer = 5
        Dim num6 As Integer = 1
        Dim respuesta As Integer = 987654

        'Do Until num1 = num6 And num2 = num5 And num3 = num4
        Do Until producto2 = 99

            respuesta = producto1 * producto2
            producto1 -= 1

            If producto1 = 100 Then
                producto1 = 999
                producto2 -= 1
            End If

            'Busca manualmente el valor de la posición de los cientos de miles

            If respuesta < 200000 And respuesta >= 100000 Then
                num1 = 1
            ElseIf respuesta < 300000 And respuesta >= 200000 Then
                num1 = 2
            ElseIf respuesta < 400000 And respuesta >= 300000 Then
                num1 = 3
            ElseIf respuesta < 500000 And respuesta >= 400000 Then
                num1 = 4
            ElseIf respuesta < 600000 And respuesta >= 500000 Then
                num1 = 5
            ElseIf respuesta < 700000 And respuesta >= 600000 Then
                num1 = 6
            ElseIf respuesta < 800000 And respuesta >= 700000 Then
                num1 = 7
            ElseIf respuesta < 900000 And respuesta >= 800000 Then
                num1 = 8
            ElseIf respuesta < 1000000 And respuesta >= 900000 Then
                num1 = 9
            Else
                num1 = 0
            End If

            'Busca manualmente el valor de la posición de las decenes de miles

            If respuesta - num1 * 100000 < 20000 And respuesta - num1 * 100000 >= 10000 Then
                num2 = 1
            ElseIf respuesta - num1 * 100000 < 30000 And respuesta - num1 * 100000 >= 20000 Then
                num2 = 2
            ElseIf respuesta - num1 * 100000 < 40000 And respuesta - num1 * 100000 >= 30000 Then
                num2 = 3
            ElseIf respuesta - num1 * 100000 < 50000 And respuesta - num1 * 100000 >= 40000 Then
                num2 = 4
            ElseIf respuesta - num1 * 100000 < 60000 And respuesta - num1 * 100000 >= 50000 Then
                num2 = 5
            ElseIf respuesta - num1 * 100000 < 70000 And respuesta - num1 * 100000 >= 60000 Then
                num2 = 6
            ElseIf respuesta - num1 * 100000 < 80000 And respuesta - num1 * 100000 >= 70000 Then
                num2 = 7
            ElseIf respuesta - num1 * 100000 < 90000 And respuesta - num1 * 100000 >= 80000 Then
                num2 = 8
            ElseIf respuesta - num1 * 100000 < 100000 And respuesta - num1 * 100000 >= 90000 Then
                num2 = 9
            Else
                num2 = 0
            End If

            'Busca manualmente el valor de la posición de los miles

            If respuesta - (num1 * 100000 + num2 * 10000) < 2000 And respuesta - (num1 * 100000 + num2 * 10000) >= 1000 Then
                num3 = 1
            ElseIf respuesta - (num1 * 100000 + num2 * 10000) < 3000 And respuesta - (num1 * 100000 + num2 * 10000) >= 2000 Then
                num3 = 2
            ElseIf respuesta - (num1 * 100000 + num2 * 10000) < 4000 And respuesta - (num1 * 100000 + num2 * 10000) >= 3000 Then
                num3 = 3
            ElseIf respuesta - (num1 * 100000 + num2 * 10000) < 5000 And respuesta - (num1 * 100000 + num2 * 10000) >= 4000 Then
                num3 = 4
            ElseIf respuesta - (num1 * 100000 + num2 * 10000) < 6000 And respuesta - (num1 * 100000 + num2 * 10000) >= 5000 Then
                num3 = 5
            ElseIf respuesta - (num1 * 100000 + num2 * 10000) < 7000 And respuesta - (num1 * 100000 + num2 * 10000) >= 6000 Then
                num3 = 6
            ElseIf respuesta - (num1 * 100000 + num2 * 10000) < 8000 And respuesta - (num1 * 100000 + num2 * 10000) >= 7000 Then
                num3 = 7
            ElseIf respuesta - (num1 * 100000 + num2 * 10000) < 9000 And respuesta - (num1 * 100000 + num2 * 10000) >= 8000 Then
                num3 = 8
            ElseIf respuesta - (num1 * 100000 + num2 * 10000) < 10000 And respuesta - (num1 * 100000 + num2 * 10000) >= 9000 Then
                num3 = 9
            Else
                num3 = 0
            End If

            'Busca manualmente el valor de la posición de las centenas

            If respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) < 200 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) >= 100 Then
                num4 = 1
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) < 300 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) >= 200 Then
                num4 = 2
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) < 400 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) >= 300 Then
                num4 = 3
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) < 500 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) >= 400 Then
                num4 = 4
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) < 600 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) >= 500 Then
                num4 = 5
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) < 700 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) >= 600 Then
                num4 = 6
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) < 800 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) >= 700 Then
                num4 = 7
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) < 900 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) >= 800 Then
                num4 = 8
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) < 1000 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000) >= 900 Then
                num4 = 9
            Else
                num4 = 0
            End If

            'Busca manualmente el valor de la posición de las decenas

            If respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) < 20 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) >= 10 Then
                num5 = 1
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) < 30 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) >= 20 Then
                num5 = 2
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) < 40 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) >= 30 Then
                num5 = 3
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) < 50 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) >= 40 Then
                num5 = 4
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) < 60 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) >= 50 Then
                num5 = 5
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) < 70 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) >= 60 Then
                num5 = 6
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) < 80 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) >= 70 Then
                num5 = 7
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) < 90 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) >= 80 Then
                num5 = 8
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) < 100 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100) >= 90 Then
                num5 = 9
            Else
                num5 = 0
            End If

            'Busca manualmente el valor de la posición de las unidades

            If respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) < 2 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) >= 1 Then
                num6 = 1
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) < 3 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) >= 2 Then
                num6 = 2
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) < 4 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) >= 3 Then
                num6 = 3
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) < 5 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) >= 4 Then
                num6 = 4
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) < 6 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) >= 5 Then
                num6 = 5
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) < 7 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) >= 6 Then
                num6 = 6
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) < 8 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) >= 7 Then
                num6 = 7
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) < 9 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) >= 8 Then
                num6 = 8
            ElseIf respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) < 10 And
                respuesta - (num1 * 100000 + num2 * 10000 + num3 * 1000 + num4 * 100 + num5 * 10) >= 9 Then
                num6 = 9
            Else
                num6 = 0
            End If

            'Imprime cada vez que el número sea palíndromo y sus productos

            If num1 = num6 And num2 = num5 And num3 = num4 And num1 = 9 Then
                Console.Write(respuesta)
                Console.Write("    ")
                Console.Write(num1)
                Console.Write(num2)
                Console.Write(num3)
                Console.Write(num4)
                Console.Write(num5)
                Console.Write(num6)
                Console.Write("    ")
                Console.Write(producto1)
                Console.Write("    ")
                Console.WriteLine(producto2)
            End If

        Loop

        'Imprime respuesta

        Console.ReadLine()

    End Sub

End Module
