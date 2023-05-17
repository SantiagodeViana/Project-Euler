Module Module1
    
    ' Solución para el problema #33 de Project Euler
    ' "Si el producto de estas cuatro fracciones se da en sus términos comunes más bajos, encuentra el valor del denominador."
    ' https://projecteuler.net/problem=33
    ' Código espagueti de 2016; optimizar

    'The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
    'We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
    'There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
    'If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
    
    Function isPrime(ByVal n As Integer) As Boolean 'Función para determinar si un numero es primo.
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
        Dim num As Integer = 11 'Numerador
        Dim dem As Integer = 12 'Denominador
        Dim num2 As Integer = Nothing 'Numerador simplificado
        Dim dem2 As Integer = Nothing 'Denominador simplificado
        Do Until dem > 99
            Dim dig1 As String = num.ToString 'Dígitos numerador
            Dim dig2 As String = dem.ToString 'Dígitos denominador
            If dig1.Substring(1, 1) = 0 Then 'Se omiten los numeradores divisibles entre 10
                num += 1
            End If
            If num = dem Or dig2.Substring(1, 1) = 0 Or isPrime(dem) Then 'Se omiten los denominadores primos, iguales al numerador o divisibles entre 10
                num = 11
                dem += 1
            End If
            If dig1.Substring(0, 1) <> dig2.Substring(0, 1) And dig1.Substring(1, 1) = dig2.Substring(1, 1) Then 'Se guardan el par de dígitos diferentes cuando el otro par es igual
                dig1 = dig1.Substring(0, 1)
                dig2 = dig2.Substring(0, 1)
            ElseIf dig1.Substring(0, 1) <> dig2.Substring(1, 1) And dig1.Substring(1, 1) = dig2.Substring(0, 1) Then
                dig1 = dig1.Substring(0, 1)
                dig2 = dig2.Substring(1, 1)
            ElseIf dig1.Substring(1, 1) <> dig2.Substring(0, 1) And dig1.Substring(0, 1) = dig2.Substring(1, 1) Then
                dig1 = dig1.Substring(1, 1)
                dig2 = dig2.Substring(0, 1)
            ElseIf dig1.Substring(1, 1) <> dig2.Substring(1, 1) And dig1.Substring(0, 1) = dig2.Substring(0, 1) Then
                dig1 = dig1.Substring(1, 1)
                dig2 = dig2.Substring(1, 1)
            End If
            Dim simple As Integer = dem / 2 + 1 'Simplificación
            Do Until num Mod simple = 0 And dem Mod simple = 0 Or simple = 2 'Se busca si la fracción es simplificable
                simple -= 1
            Loop
            If num Mod simple = 0 And dem Mod simple = 0 Then 'Si la fracción es simplificable se expresa en los términos menores
                num2 = num / simple
                dem2 = dem / simple
                Dim num3 As Char = num2.ToString
                Dim dem3 As Char = dem2.ToString
                If dig1 = num3 And dig2 = dem3 And dem2 < 10 Then
                    Console.WriteLine(num & "   " & dem & "   " & simple & "   " & num2 & "   " & dem2)
                End If
                If dig1 <> num3 And dig2 <> dem3 Then 'Si la fracción no tiene dígitos de la primera expresión se busca expresar de esa manera
                    simple = 2
                    Do Until simple >= dem / 2 + 1 Or dig1 = num3 And dig2 = dem3 Or (num2 * simple) >= num Or (dem2 * simple) >= dem 'Buscar expresiones de la fracción con la propiedad
                        num2 *= simple
                        dem2 *= simple
                        num3 = num2.ToString
                        dem3 = dem2.ToString
                        If dig1 <> num3 And dig2 <> dem3 Then
                            num2 /= simple
                            dem2 /= simple
                        End If
                        simple += 1
                        If dig1 = num3 And dig2 = dem3 And dem2 < 10 Then 'Fracciones que parecieron ser simplificados eliminando los dígitos
                            Console.WriteLine(num & "   " & dem & "   " & simple & "   " & num2 & "   " & dem2)
                        End If
                    Loop
                End If
            End If
            'Console.Write(num & "   " & dem & "   " & simple & "   " & num2 & "   " & dem2)
            'Console.ReadLine()
            num += 1
        Loop
        Console.WriteLine("Ditto") 'Por una parte conseguí que el programa buscar la cuarta fracción cuya propiedad no se cumple en los términos menores (1/2 tiene que ser expresada como 4/8)
        Console.ReadLine() 'Por otra parte olvidé simplificar 1/5 * 1/4 * 2/5 * 1/2 = 2/200 ... fuck me, quizás fue para lo mejor
        'La respuesta es 100
    End Sub
End Module
