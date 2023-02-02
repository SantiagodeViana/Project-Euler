Module Module1
  
    ' Solución para el problema #17 de Project Euler
    ' "¿Si todos los números del 1 al 1000 (mil) inclusive se escribieran en palabras, ¿cuántas letras se utilizarían?"
    ' https://projecteuler.net/problem=17
    ' Código espagueti de 2016; optimizar

    Dim n As Integer = Nothing
    Dim word As String = Nothing
    Dim respuesta As Integer = Nothing
    Function numberLetters(ByVal n As Integer)
        word = Integer.Parse(n)
        If n >= 100 Then 'Si es una centena
            If word.Substring(0, 1) = 1 Or word.Substring(0, 1) = 2 Or word.Substring(0, 1) = 6 Then 'Trece letras
                respuesta += 10 'One, two, six hundred
            ElseIf word.Substring(0, 1) = 4 Or word.Substring(0, 1) = 5 Or word.Substring(0, 1) = 9 Then 'Catorce letras
                respuesta += 11 'Four, five, nine hundred
            ElseIf word.Substring(0, 1) = 3 Or word.Substring(0, 1) = 7 Or word.Substring(0, 1) = 8 Then 'Quince letras
                respuesta += 12 'Three, seven, eight hundred
            End If

            If word.Substring(1, 1) <> 0 Or word.Substring(2, 1) <> 0 Then
                respuesta += 3 'and
            End If
        End If
        If n >= 20 Then 'Si es una decena
            If word.Substring(0 + word.Length - 2, 1) = 4 Or word.Substring(0 + word.Length - 2, 1) = 5 Or word.Substring(0 + word.Length - 2, 1) = 6 Then 'Cinco letras
                respuesta += 5 'Forty, fifty, sixty
            ElseIf word.Substring(0 + word.Length - 2, 1) = 2 Or word.Substring(0 + word.Length - 2, 1) = 3 Or word.Substring(0 + word.Length - 2, 1) = 8 Or word.Substring(0 + word.Length - 2, 1) = 9 Then 'Seis letras
                respuesta += 6 'Twenty, thirty, eighty, ninety
            ElseIf word.Substring(0 + word.Length - 2, 1) = 7 Then 'Siete letras
                respuesta += 7 'Seventy
            End If
        End If
        If n >= 10 Then 'Diesi-
            If word.Substring(0 + word.Length - 2, 1) = 1 Then
                If 1 And word.Substring(0 + word.Length - 1, 1) = 1 Or 1 And word.Substring(0 + word.Length - 1, 1) = 2 Then 'Seis letras
                    respuesta += 6 'Eleven, twelve
                ElseIf 1 And word.Substring(0 + word.Length - 1, 1) = 5 Or 1 And word.Substring(0 + word.Length - 1, 1) = 6 Then 'Siete letras
                    respuesta += 7 'Fifteen, sixteen
                ElseIf 1 And word.Substring(0 + word.Length - 1, 1) = 3 Or 1 And word.Substring(0 + word.Length - 1, 1) = 4 Or 1 And word.Substring(0 + word.Length - 1, 1) = 8 And 1 Or word.Substring(0 + word.Length - 1, 1) = 9 Then 'Ocho letras
                    respuesta += 8 'Thirteen, fourteen, eighteen, nineteen
                ElseIf 1 And word.Substring(0 + word.Length - 1, 1) = 7 Then 'Nueve letras
                    respuesta += 9 'Seventeen
                ElseIf word.Substring(0 + word.Length - 1, 1) = 0 Then
                    respuesta += 3 'Ten
                End If
            Else 'Si es una unidad
                If word.Substring(0 + word.Length - 1, 1) = 1 Or word.Substring(0 + word.Length - 1, 1) = 2 Or word.Substring(0 + word.Length - 1, 1) = 6 Then 'Tres letras
                    respuesta += 3 'One, two, six
                ElseIf word.Substring(0 + word.Length - 1, 1) = 4 Or word.Substring(0 + word.Length - 1, 1) = 5 Or word.Substring(0 + word.Length - 1, 1) = 9 Then 'Cuatro letras
                    respuesta += 4 'Four, five, nine
                ElseIf word.Substring(0 + word.Length - 1, 1) = 3 Or word.Substring(0 + word.Length - 1, 1) = 7 Or word.Substring(0 + word.Length - 1, 1) = 8 Then 'Cinco letras
                    respuesta += 5 'Three, seven, eight
                Else
                    respuesta += 0
                End If
            End If
        End If
        If n = 1 Or n = 2 Or n = 6 Then 'Tres letras
            respuesta += 3
        ElseIf n = 4 Or n = 5 Or n = 9 Then 'Cuatro letras
            respuesta += 4
        ElseIf n = 3 Or n = 7 Or n = 8 Then 'Cinco letras
            respuesta += 5
        Else
            respuesta += 0
        End If
        Return True
    End Function
    Sub Main()
        Do Until n = 999
            n += 1
            numberLetters(n)
            Console.WriteLine(n & "   " & respuesta)
        Loop
        respuesta += 11 'One thousand
        Console.WriteLine("La respuesta es " & respuesta) 'La respuesta es 21124
        Console.ReadLine()
    End Sub
End Module
