Module Module1

  ' Solución para el problema #46 de Project Euler
  ' "¿Cuál es el compuesto impar más pequeño que no se puede escribir como la suma de un primo y dos veces un cuadrado?"
  ' https://projecteuler.net/problem=46
  ' Código de 2016; optimizar

  Function isPrime(ByVal n As Integer) As Integer 'Función para determinar si un número es primo.
        If n = 1 Then
            Return False
        ElseIf n < 4 Then
            Return True
        ElseIf n Mod 2 = 0 Then
            Return False
        ElseIf n < 9 Then
            Return True
        ElseIf n Mod 3 = 0 Then
            Return False
        Else
            Dim r As Integer = Math.Floor(Math.Sqrt(n))
            Dim f As Integer = 5
            Do While f <= r
                If n Mod f = 0 Then
                    Return False
                ElseIf n Mod (f + 2) = 0 Then
                    Return False
                Else
                    f += 6
                End If
            Loop
            Return True
        End If
    End Function

    Sub Main()

        Dim respuesta As Integer = 0
        Dim conjecture As Boolean = True
        Dim compuesto As Long = 9
        Dim suma As Long = 1
        Dim primo As Integer = 2
        Dim n As Integer = 1
        Dim cuadrado As Integer = 1

        Do Until conjecture = False

            'Look for a number that is a prime

            n += 2

            'If the number is a prime, then it'll be added to the formula

            If isPrime(n) Then
                primo = n
            End If

            'If the prime is larger than the composite, the base of the square will increase

            If primo > compuesto Then
                cuadrado += 1
                Console.Write(compuesto)
                Console.Write("   ")
                Console.Write(n)
                Console.Write("   ")
                Console.Write(primo)
                Console.Write("   ")
                Console.Write(cuadrado)
                Console.Write("   ")
                Console.Write(suma)
                Console.Write("   ")
                Console.WriteLine(conjecture)
                n = 1
                primo = 2
            End If

            suma = primo + (2 * (cuadrado) ^ 2)

            'Restart the process once the conjecture is proved or if we don't have a composite

            If compuesto = suma Or isPrime(compuesto) Then
                compuesto += 2
                n = 1
                cuadrado = 1
                primo = 2
            End If

            'If the conjecture isn't true after the sum is as twice as the composite, then it's false

            If suma > compuesto * 2 Then
                conjecture = False
            End If

            'The answer is the first composite when the conjecture is false

            If conjecture = False Then
                respuesta = compuesto
            End If

        Loop

        'Output answer

        Console.Write(" La respuesta es ")
        Console.Write(respuesta)
        Console.ReadLine()

    End Sub

End Module
