Module Module1

    Sub Main()
        ' Solución para el problema #9 de Project Euler
        ' "Existe exactamente un triplete pitagórico para el que a + b + c = 1000. Encuentra el producto a*b*c"
        ' https://projecteuler.net/problem=9
        ' Código espagueti de 2015; optimizar

        'Este programa busca el producto del triplete de Pitágoras a + b + c = 1000

        Dim teorema As Boolean = False
        Dim suma As Boolean = False
        Dim a As Integer = 1
        Dim b As Integer = 1
        Dim c As Integer = 1
        Dim respuesta As Integer = 0

        Do Until teorema = True And suma = True

            suma = (a + b + c = 1000)
            teorema = (a ^ 2 + b ^ 2 = c ^ 2)

            'Se busca números conociendo las condiciones previas y que a > b > c

            If a = 1000 Or a > b Then
                a = 1
                b += 1
            ElseIf b = 1000 Or b > c Then
                b = 1
                c += 1
            Else
                a += 1
            End If
        Loop

        a -= 1

        'Imprime números conseguidos cuando tanto el teorema como la suma se obedecen

        Console.Write(a)
        Console.Write("   ")
        Console.Write(b)
        Console.Write("   ")
        Console.Write(c)
        Console.Write("   ")
        Console.Write(teorema)
        Console.Write("   ")
        Console.Write(suma)
        Console.ReadLine()

        'Se imprime la respuesta, el producto del triplete

        respuesta = a * b * c

        Console.Write("La respuesta es ")
        Console.Write(respuesta)
        Console.ReadLine()

    End Sub

End Module
