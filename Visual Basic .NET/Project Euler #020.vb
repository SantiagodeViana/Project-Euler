Module Module1

    Sub Main()
        Dim n As Integer = 1
        Dim n1 As Integer = 0
        Dim respuesta As Long = 1

        ' Solución para el problema #20 de Project Euler
        ' "Encuentra la suma de los dígitos del número 100!"
        ' https://projecteuler.net/problem=20
        ' Código espagueti de 2016; optimizar

        Do Until n = 100

            'Overflow cuando n = 95 o n = 14, dependiendo de a partir de donde se multiplique

            'n1 = n
            'n += 1
            'respuesta = respuesta * n * n1 '.ToString?
            'Console.Write(n)
            'Console.Write("   ")
            'Console.Write(n1)

            respuesta = (2 * 3) * (4 * 5) * 6 * 7 * 8 * 9 * 11 * 12 * 13

            'Se pueden remover los ceros de las decenas; por ejemplo, 10, 20, 30, multiplicando por 1, 2 y 3 respectivamente

            Console.Write("   ")
            Console.WriteLine(respuesta)

        Loop

        Console.WriteLine(respuesta)
        Console.ReadLine()

    End Sub
    
 End Module
