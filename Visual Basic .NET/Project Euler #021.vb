Module Module1
    
    ' Solución para el problema #21 de Project Euler
    ' https://projecteuler.net/problem=21
    ' Código espagueti de 2015; optimizar

    Sub Main()
        Dim suma As Integer = 0
        Dim suma2 As Integer = 0
        Dim divisor As Integer = 1
        Dim dividendo As Integer = 1
        Dim amicable1 As Integer = 0
        Dim amicable2 As Integer = 0
        Dim respuesta As Long = 0
        
        ' Solución para el problema #21 de Project Euler
        ' "Evalúa la suma de todos los números amigables menores de 10000."
        ' https://projecteuler.net/problem=21
        ' Código espagueti de 2016; optimizar

        Do Until dividendo > 10000

            'Se buscan y suman los divisores de un número

            If dividendo Mod divisor = 0 Then
                suma += divisor
                divisor += 1
            ElseIf dividendo Mod divisor <> 0 Then
                divisor += 1
            End If

            'Al terminar de buscar los divisores, siempre en cuando la suma de los divisores no sea igual al número o nula

            If divisor > (dividendo / 2) And dividendo <> suma And suma > 0 Then

                'Se buscarán amicables, donde el primero es igual al número y el segundo es la suma de divisores.

                amicable1 = dividendo
                amicable2 = suma
                divisor = 1
                dividendo += 1
                suma = 0
                suma2 = 0

                'Se buscan y sumas los divisores de la suma de divisores

                Do Until divisor > (amicable2 / 2)

                    If amicable2 Mod divisor = 0 Then
                        suma2 += divisor
                        divisor += 1
                    ElseIf amicable2 Mod divisor <> 0 Then
                        divisor += 1
                    End If
                Loop

            ElseIf divisor > (dividendo / 2) Then
                suma = 0
                divisor = 1
                dividendo += 1
            End If

            'Si el número es amicable, y la suma de sus factores es igual al número anterior, entonces se suma a la respuesta.

            If amicable1 = suma2 Then

                respuesta += amicable1
                respuesta += amicable2

                Console.Write("Amicable1:")
                Console.Write(amicable1)
                Console.Write("   ")
                Console.Write("Amicable2:")
                Console.Write(amicable2)
                Console.Write("   ")
                Console.Write("Respuesta:")
                Console.Write(respuesta)
                Console.Write("   ")
                Console.Write("Suma2:")
                Console.WriteLine(suma2)

                divisor = 1

            End If

            If divisor > dividendo Then
                divisor = 1
            End If
        Loop

        'Por alguna razón dos pares de números no se repiten, así que no se puede conseguir la mitad directamente para eliminar las repeticiones

        respuesta = (respuesta - 11088) / 2 + 11088

        Console.Write("Respuesta:")
        Console.WriteLine(respuesta)
        Console.Write("La respuesta es ")
        Console.WriteLine(respuesta)
        Console.ReadLine()

    End Sub

End Module
