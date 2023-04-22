Module Module1
    Sub Main()

        'In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

        '1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
        'It is possible to make £2 in the following way:

        '1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
        'How many different ways can £2 be made using any number of coins?

        Dim coins = New Integer() {200, 100, 50, 10, 5, 2, 1}
        Dim money As Integer = 10
        Dim amount As Integer = Nothing
        Dim last As Integer = Nothing
        Dim count As Integer = Nothing
        Dim residuo As Integer = Nothing
        Dim respuesta As Integer = Nothing
        Dim n As Integer = Nothing
        Dim n2 As Integer = Nothing

        'Aritmética modular, resuelve a partir del residuo y la división de las monedas
        Do Until coins(n) = 1
            amount = (money / coins(n))
            residuo = (money Mod coins(n))
            If residuo Mod coins(n) = 0 And residuo <> 0 Then
                residuo = 0
                amount += 1
            End If
            If amount > 0 Then
                last = amount
            End If
            If amount = 0 Then
                last += 1
            End If
            amount -= 1
            respuesta += 1
            Console.Write(money & "   " & coins(n) & "   " & amount & "   " & residuo & "   " & respuesta)
            Console.ReadLine()
            n += 1
        Loop
        Console.WriteLine("La respuesta es " & respuesta)
        Console.ReadLine()
    End Sub
End Module
