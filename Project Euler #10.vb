Module Module1

    Sub Main()
    
        ' Solución para el problema #10 de Project Euler
        ' "Halla la suma de todos los números primos inferiores a dos millones."
        ' https://projecteuler.net/problem=10
        ' Código espagueti de 2015; optimizar

        'El programa suma todos los primos menores de dos millones (2000000)

        Dim divisor As Integer = 1
        Dim dividendo As Integer = 1
        Dim cuenta As Integer = 2
        Dim limite As Integer = 2000000
        Dim suma As Long = 0

        Do Until dividendo > limite

            'Como se ha hecho en programas anteriores, el método de búsqueda es sencillo
            'Se buscan primos sabiendo que son números que no pueden ser divididos por ningún número hasta su raíz cuadrada
            'El programa se detiene hasta alcanzar el límite

            If dividendo Mod divisor <> 0 And divisor > Math.Sqrt(dividendo) Then
                suma += dividendo
                dividendo += 2
                divisor = 3
                cuenta += 1

                'Console.Write(dividendo)
                'Console.Write("  ")
                'Console.Write("  ")
                'Console.Write(cuenta)
                'Console.Write("  ")
                'Console.WriteLine(suma)

            ElseIf dividendo Mod divisor = 0 Then
                dividendo += 2
                divisor = 3
            ElseIf divisor > dividendo Then
                divisor = 3
            Else
                divisor += 2
            End If

        Loop

        Console.Write(dividendo)
        Console.Write("  ")
        Console.Write("  ")
        Console.Write(cuenta)
        Console.Write("  ")
        Console.Write(suma)
        Console.WriteLine()

        Console.Write("La respuesta es ")
        Console.Write(suma)
        Console.ReadLine()

        '2 y 5 no están siendo contados

    End Sub

End Module
