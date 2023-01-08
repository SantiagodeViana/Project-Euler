Module Module1

    Sub Main()
        ' Solución para el problema #14 de Project Euler
        ' "¿Qué número inicial, por debajo de un millón, produce la cadena más larga?"
        ' https://projecteuler.net/problem=14
        ' Código espagueti de 2016; optimizar
    
        'El siguiente programa encuentra al número que genera la secuencia de Collatz más larga.

        Dim n As Long = 0
        Dim n1 As Integer = 1000000
        Dim cuenta As Integer = 0
        Dim respuesta As Long = 0
        Dim respuesta2 As Integer = 0

        n = n1

        Do Until n1 = 1

            'Se cuenta el número de pasos en la secuencia, y se mantiene el más largo; se identifica al número que generó la secuencia

            If cuenta > respuesta Then
                respuesta = cuenta
                respuesta2 = n1
                Console.Write(n1)
                Console.Write("    ")
                Console.Write(respuesta)
                Console.Write("    ")
                Console.WriteLine(respuesta2)
            End If

            'Cuando la secuencia termina, se siguen buscando números y se repite el proceso

            If n = 1 Then
                n1 -= 1
                n = n1
                cuenta = 0
            End If

            'Secuencia de Collatz: cuando n es impar = 3n + 1; cuando es par es igual a su mitad. Se espera que siempre termine en 1.

            If n Mod 2 <> 0 Then
                n = (3 * n) + 1
                cuenta += 1
            ElseIf n Mod 2 = 0 Then
                n = n / 2
                cuenta += 1
            End If
        Loop

        Console.Write("La respuesta es ")
        Console.WriteLine(respuesta2)
        Console.ReadLine()

    End Sub

End Module
