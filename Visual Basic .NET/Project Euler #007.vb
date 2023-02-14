Module Module1

    Sub Main()
      '  Solución para el problema #7 de Project Euler
      ' "¿Cuál es el 10 001º número primo?"
      ' https://projecteuler.net/problem=7   
      ' Código espagueti de 2015; optimizar

        Dim divisor As Integer = 1
        Dim dividendo As Integer = 1
        Dim cuenta As Integer = 2
        Dim limite As Integer = 10001

        Do Until cuenta = limite

            'Busca primos al determinar si se pueden dividir por algún número hasta su raíz cuadrada.

            If dividendo Mod divisor <> 0 And divisor > Math.Sqrt(dividendo) Then

                dividendo += 2
                divisor = 3
                cuenta += 1


            ElseIf dividendo Mod divisor = 0 Then
                dividendo += 2
                divisor = 3

            ElseIf divisor > dividendo Then
                divisor = 3
            Else
                divisor += 2

            End If
        Loop

        'Imprime respuesta

        Console.Write("La respuesta es ")
        Console.Write(dividendo - 2)
        Console.ReadLine()

    End Sub

End Module
