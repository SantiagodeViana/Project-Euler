Module Module1
    Sub Main()
        Dim ladosPiramidales() = New Integer(8) {1, 1, 1, 1, 1, 1, 1, 1, 1}
        Dim ladosCubicos() = New Integer(5) {1, 1, 1, 1, 1, 1}
        Dim n1 = ladosPiramidales.Length - 1
        Dim n2 = ladosCubicos.Length - 1
        Dim denominador As Long = Nothing
        Dim numerador As Long = Nothing
        Dim respuesta As Decimal = Nothing
        'Prime bucle: Determina el denominador
        Do Until ladosCubicos(0) = 6 And ladosCubicos(1) = 6 And ladosCubicos(2) = 6 And ladosCubicos(3) = 6 And ladosCubicos(4) = 6 And ladosCubicos(5) = 6 And ladosPiramidales(0) = 4 And ladosPiramidales(1) = 4 And ladosPiramidales(2) = 4 And ladosPiramidales(3) = 4 And ladosPiramidales(4) = 4 And ladosPiramidales(5) = 4 And ladosPiramidales(6) = 4 And ladosPiramidales(7) = 4 And ladosPiramidales(8) = 4
            If ladosPiramidales(0) = 4 And ladosPiramidales(1) = 4 And ladosPiramidales(2) = 4 And ladosPiramidales(3) = 4 And ladosPiramidales(4) = 4 And ladosPiramidales(5) = 4 And ladosPiramidales(6) = 4 And ladosPiramidales(7) = 4 And ladosPiramidales(8) = 4 Then
                Do Until ladosCubicos(n2) <= 6
                    ladosCubicos(n2) = 1
                    n2 -= 1
                    ladosCubicos(n2) += 1
                    If ladosCubicos(n2) <= 6 Then
                        n2 = ladosCubicos.Length - 1
                    End If
                    denominador += 1
                Loop
                ladosPiramidales(0) = 1
                ladosPiramidales(1) = 1
                ladosPiramidales(2) = 1
                ladosPiramidales(3) = 1
                ladosPiramidales(4) = 1
                ladosPiramidales(5) = 1
                ladosPiramidales(6) = 1
                ladosPiramidales(7) = 1
                ladosPiramidales(8) = 1
                Console.WriteLine(ladosPiramidales(0) & ladosPiramidales(1) & ladosPiramidales(2) & ladosPiramidales(3) & ladosPiramidales(4) & ladosPiramidales(5) & ladosPiramidales(6) & ladosPiramidales(7) & ladosPiramidales(8) & "   " & ladosCubicos(0) & ladosCubicos(1) & ladosCubicos(2) & ladosCubicos(3) & ladosCubicos(4) & ladosCubicos(5) & "   " & numerador & "   " & denominador & "   " & respuesta)
                ladosCubicos(n2) += 1
            End If
            Do Until ladosPiramidales(n1) <= 4
                ladosPiramidales(n1) = 1
                n1 -= 1
                ladosPiramidales(n1) += 1
                If ladosPiramidales(n1) <= 4 Then
                    n1 = ladosPiramidales.Length - 1
                End If
            Loop
            If (ladosPiramidales(0) + ladosPiramidales(1) + ladosPiramidales(2) + ladosPiramidales(3) + ladosPiramidales(4) + ladosPiramidales(5) + ladosPiramidales(6) + ladosPiramidales(7) + ladosPiramidales(8)) > (ladosCubicos(0) + ladosCubicos(1) + ladosCubicos(2) + ladosCubicos(3) + ladosCubicos(4) + ladosCubicos(5)) Then
                numerador += 1 'Segundo bucle: Determina el numerador
            End If
            denominador += 1
            If denominador <> 0 Then
                respuesta = numerador / denominador
            End If
            If ladosCubicos(0) = 6 And ladosCubicos(1) = 6 And ladosCubicos(2) = 6 And ladosCubicos(3) = 6 And ladosCubicos(4) = 6 Then
                Console.WriteLine(ladosPiramidales(0) & ladosPiramidales(1) & ladosPiramidales(2) & ladosPiramidales(3) & ladosPiramidales(4) & ladosPiramidales(5) & ladosPiramidales(6) & ladosPiramidales(7) & ladosPiramidales(8) & "   " & ladosCubicos(0) & ladosCubicos(1) & ladosCubicos(2) & ladosCubicos(3) & ladosCubicos(4) & ladosCubicos(5) & "   " & numerador & "   " & denominador & "   " & respuesta)
                'Console.ReadLine()
            End If
            ladosPiramidales(n1) += 1
        Loop
        Console.WriteLine(ladosPiramidales(0) & ladosPiramidales(1) & ladosPiramidales(2) & ladosPiramidales(3) & ladosPiramidales(4) & ladosPiramidales(5) & ladosPiramidales(6) & ladosPiramidales(7) & ladosPiramidales(8) & "   " & ladosCubicos(0) & ladosCubicos(1) & ladosCubicos(2) & ladosCubicos(3) & ladosCubicos(4) & ladosCubicos(5) & "   " & numerador & "   " & denominador & "   " & respuesta)
        Console.WriteLine("La respuesta es: " & respuesta)
        Console.ReadLine()
    End Sub
End Module
