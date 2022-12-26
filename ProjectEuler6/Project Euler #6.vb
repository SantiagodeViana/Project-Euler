Module Module1
    '  Solución para el problema #6 de Project Euler
    ' "Halla la diferencia entre la suma de los cuadrados de los cien primeros números naturales y el cuadrado de la suma."
    ' https://projecteuler.net/problem=6   
    ' Código espagueti de 2015; considerar optimización

    Sub Main()
        Dim base As Integer = 0
        Dim suma1 As Integer = 0
        Dim suma2 As Integer = 0
        Dim cuadrado As Integer = 0
        Dim respuesta As Integer = 0

        'Suma de los cien primeros cuadrados

        Do Until base > 100
            cuadrado = base ^ 2
            suma1 = suma1 + cuadrado
            base += 1
            Console.WriteLine(cuadrado)
        Loop
        Console.ReadLine()
        Console.WriteLine(suma1)
        Console.ReadLine()
        base = 0

        'Cuadrado de la suma de los primeros cien números naturales

        Do Until base > 100
            suma2 = suma2 + base
            base += 1
            Console.WriteLine(suma2)
        Loop

        Console.ReadLine()
        suma2 = suma2 ^ 2
        Console.WriteLine(suma2)
        Console.ReadLine()

        'Determina la diferencia entre ambas. Imprime resultado

        respuesta = suma2 - suma1
        Console.Write("La respuesta es ")
        Console.Write(respuesta)
        Console.ReadLine()

    End Sub

End Module
