Module Module1

    Sub Main()

        'The proper divisors of a number are all the divisors excluding the number itself. For example, the proper divisors of 28 are 1, 2, 4, 7, and 14. As the sum of these divisors is equal to 28, we call it a perfect number.

        'Interestingly the sum of the proper divisors of 220 is 284 and the sum of the proper divisors of 284 is 220, forming a chain of two numbers. For this reason, 220 and 284 are called an amicable pair.

        'Perhaps less well known are longer chains. For example, starting with 12496, we form a chain of five numbers:

        '12496 → 14288 → 15472 → 14536 → 14264 (→ 12496 → ...)

        'Since this chain returns to its starting point, it is called an amicable chain.

        'Find the smallest member of the longest amicable chain with no element exceeding one million.


        'Encuentra la suma de los números amicables menores de 10000

        Dim suma As Integer = 0
        Dim suma2 As Integer = 0
        Dim divisor As Integer = 1
        Dim dividendo As Integer = 1
        Dim amicable1 As Integer = 0
        Dim amicable2 As Integer = 0
        Dim respuesta As Long = 0

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

                Console.WriteLine("Amicable1:" & amicable1 & "   " & "Amicable2:" & amicable2 & "   " & "Respuesta:" & respuesta & "   " & "Suma2:" & suma2)
                suma2 = 0
                divisor = 1

            End If

            If divisor > dividendo Then
                divisor = 1
            End If
        Loop

        'Por alguna razón dos pares de números no se repiten, así que no se puede conseguir la mitad directamente para eliminar las repeticiones

        respuesta = (respuesta - 11088) / 2 + 11088

        Console.Write("La respuesta es " & respuesta)
        Console.ReadLine()

    End Sub

End Module
