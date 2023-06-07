Module Module1
    Sub Main()
        
        ' Solución para el problema #44 de Project Euler
        ' "Encuentra la diferencia entre el par de números pentagonales cuya suma y diferencia también son pentagonales."
        ' https://projecteuler.net/problem=44
        ' Código de 2016; optimizar
               
        Dim n1 As Integer = 1
        Dim n2 As Integer = 1
        Dim cuenta1 As Integer = 1
        Dim cuenta2 As Integer = 2
        Dim pentagonal As Boolean = False
        Dim suma As Long = 0
        Dim diferencia As Long = 0
        Dim respuesta As Long = 0
        Dim limite As Integer = 100000
        Do Until respuesta <> 0
            'Se buscan números pentagonales usando la fórmula n(3n-1) / 2 
            cuenta1 += 1
            n1 = cuenta1 * ((3 * cuenta1) - 1) / 2
            n2 = cuenta2 * ((3 * cuenta2) - 1) / 2
            'Se guardan la suma y la diferencia respectiva del par
            suma = n1 + n2
            diferencia = Math.Abs(n1 - n2)
            'El par tiene que tener una suma y una diferencia también pentagonales. Esto se determina mediante la fórmula reversa.

            pentagonal = ((Math.Sqrt(24 * suma + 1) + 1) / 6) Mod 1 = 0 And ((Math.Sqrt(24 * diferencia + 1) + 1) / 6) Mod 1 = 0
            'La respuesta es el valor absoluto de la diferencia.
            If pentagonal = True Then
                respuesta = Math.Abs(diferencia)
            End If
            'Después de cierto límite, el segundo número pentagonal incrementa, de manera que todos los números pentagonales se comprueben.
            If n1 > limite Then
                cuenta1 = 1
                cuenta2 += 1
            End If
            If n2 > limite Then
                cuenta1 = 1
                cuenta2 = 1
                limite += 100000
            End If
        Loop
        'Imprime datos y respuesta
        'Tiempo aprox: 20 seg.
        Console.WriteLine(n1 & "   " & n2 & "   " & cuenta1 & "   " & cuenta2 & "   " & suma & "   " & diferencia & "   " & respuesta)
        Console.Write("La respuesta es " & respuesta)
        Console.ReadLine()
    End Sub
End Module
