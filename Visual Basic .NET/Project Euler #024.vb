Module Module1
    Sub Main()
        Dim x0 As Integer = 0
        Dim x1 As Integer = 1
        Dim x2 As Integer = 2
        Dim x3 As Integer = 3
        Dim x4 As Integer = 4
        Dim x5 As Integer = 5
        Dim x6 As Integer = 6
        Dim x7 As Integer = 7
        Dim x8 As Integer = 8
        Dim x9 As Integer = 9
        Dim xmax As Integer = 10
        Dim n As Integer = 0

        'Buscar la millónesima combinación de 0123456789

        Do Until n = 1000000

            'Cuando una cifra llega a la decena

            If x1 = x0 Then
                x1 += 1
            ElseIf x1 = xmax Or x2 = x1 Or x2 = x0 Then
                x2 += 1
            ElseIf x2 = xmax Or x3 = x2 Or x3 = x1 Or x3 = x0 Then
                x3 += 1
            ElseIf x3 = xmax Or x4 = x3 Or x4 = x2 Or x4 = x1 Or x4 = x0 Then
                x4 += 1
            ElseIf x4 = xmax Or x5 = x4 Or x5 = x3 Or x5 = x2 Or x5 = x1 Or x5 = x0 Then
                x5 += 1
            ElseIf x5 = xmax Or x6 = x5 Or x6 = x4 Or x6 = x3 Or x6 = x2 Or x6 = x1 Or x6 = x0 Then
                x6 += 1
            ElseIf x6 = xmax Or x7 = x6 Or x7 = x5 Or x7 = x4 Or x7 = x3 Or x7 = x2 Or x7 = x1 Or x7 = x0 Then
                x7 += 1
            ElseIf x7 = xmax Or x8 = x7 Or x8 = x6 Or x8 = x5 Or x8 = x4 Or x8 = x3 Or x8 = x2 Or x8 = x1 Or x8 = x0 Then
                x8 += 1
            ElseIf x8 = xmax Or x9 = x8 Or x9 = x7 Or x9 = x6 Or x9 = x5 Or x9 = x4 Or x9 = x3 Or x9 = x2 Or x9 = x1 Or x9 = x0 Then
                x9 += 1
            ElseIf x0 = x8 Or x0 = x7 Or x0 = x6 Or x0 = x5 Or x0 = x4 Or x0 = x3 Or x0 = x2 Or x0 = x1 Then
                x0 += 1
            End If

            'Si las cifras se repiten, continuar a la próxima posiblidad	

            If x9 <> x8 And x0 <> xmax And x0 <> x8 And x0 <> x7 And x0 <> x6 And x0 <> x5 And x0 <> x4 And x0 <> x3 And x0 <> x2 And x0 <> x1 And
                x9 <> xmax And x9 <> x7 And x9 <> x6 And x9 <> x5 And x9 <> x4 And x9 <> x3 And x9 <> x2 And x9 <> x1 And x9 <> x0 And
                x8 <> xmax And x8 <> x7 And x8 <> x6 And x8 <> x5 And x8 <> x4 And x8 <> x3 And x8 <> x2 And x8 <> x1 And x8 <> x0 And
                x7 <> xmax And x7 <> x6 And x7 <> x5 And x7 <> x4 And x7 <> x3 And x7 <> x2 And x7 <> x1 And x7 <> x0 And
                x6 <> xmax And x6 <> x5 And x6 <> x4 And x6 <> x3 And x6 <> x2 And x6 <> x1 And x6 <> x0 And
                x5 <> xmax And x5 <> x4 And x5 <> x3 And x5 <> x2 And x5 <> x1 And x5 <> x0 And
                x4 <> xmax And x4 <> x3 And x4 <> x2 And x4 <> x1 And x4 <> x0 And
                x3 <> xmax And x3 <> x2 And x3 <> x1 And x3 <> x0 And
                x2 <> xmax And x2 <> x1 And x2 <> x0 And
                x1 <> xmax And x1 <> x0 Then

                If n Mod 25000 = 0 Then
                    Console.WriteLine(x0 & x1 & x2 & x3 & x4 & x5 & x6 & x7 & x8 & x9 & "     " & n)
                End If

                x9 += 1
                n += 1
            End If

            If x1 >= xmax Then
                x0 += 1
                x1 = 0
                x2 = 0
                x3 = 0
                x4 = 0
                x5 = 0
                x6 = 0
                x7 = 0
                x8 = 0
                x9 = 0
            ElseIf x2 >= xmax Then
                x1 += 1
                x2 = 0
                x3 = 0
                x4 = 0
                x5 = 0
                x6 = 0
                x7 = 0
                x8 = 0
                x9 = 0
            ElseIf x3 >= xmax Then
                x2 += 1
                x3 = 0
                x4 = 0
                x5 = 0
                x6 = 0
                x7 = 0
                x8 = 0
                x9 = 0
            ElseIf x4 >= xmax Then
                x3 += 1
                x4 = 0
                x5 = 0
                x6 = 0
                x7 = 0
                x8 = 0
                x9 = 0
            ElseIf x5 >= xmax Then
                x4 += 1
                x5 = 0
                x6 = 0
                x7 = 0
                x8 = 0
                x9 = 0
            ElseIf x6 >= xmax Then
                x5 += 1
                x6 = 0
                x7 = 0
                x8 = 0
                x9 = 0
            ElseIf x7 >= xmax Then
                x6 += 1
                x7 = 0
                x8 = 0
                x9 = 0
            ElseIf x8 >= xmax Then
                x7 += 1
                x8 = 0
                x9 = 0
            ElseIf x9 >= xmax Then
                x8 += 1
                x9 = 0
            End If

            'Console.Write(x0 & x1 & x2 & x3 & x4 & x5 & x6 & x7 & x8 & x9 & "   " & n)
            'Console.ReadLine()

        Loop

        'Imprime respuesta
        Console.Write("La respuesta es " & x0 & x1 & x2 & x3 & x4 & x5 & x6 & x7 & x8 & x9 - 1)
        Console.ReadLine()
    End Sub
End Module
