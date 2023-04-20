Module Module1
    
    ' Solución para el problema #29 de Project Euler
    ' "¿Cuántos términos distintos hay en la secuencia generada por a^b para 2 ≤ a ≤ 100 y 2 ≤ b ≤ 100?"
    ' https://projecteuler.net/problem=29
    ' Código espagueti de 2016; optimizar
    
    Sub Main()
        Dim a As Integer = 1
        Dim b As Integer = 1
        Dim respuesta As Integer = Nothing
        'How many distinct terms are in the sequence generated by ab for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?
        Do Until a = 100
            a += 1 'Base +1
            If a = 4 Or a = 9 Or a = 16 Or a = 25 Or a = 36 Or a = 49 Or a = 64 Or a = 81 Or a = 100 Then 'Cuadrados perfectos
                b = 50
            End If
            Do Until b = 100 'Hasta que exponente = 100
                b += 1 'Exponente +1
                respuesta += 1 'Factor +1
                Console.WriteLine(a & "   " & b & "   " & respuesta)
            Loop
            b = 1
        Loop
        Console.WriteLine("La respuesta es " & respuesta)
        Console.ReadLine()
    End Sub
End Module
