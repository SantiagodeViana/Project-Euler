Module Module1
    Sub Main()

        'A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

        'The text file, keylog.txt, contains fifty successful login attempts.

        'Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.

        Dim login() = New String(49) {"319", "680", "180", "690", "129", "620", "762", "689", "762", "318", "368", "710", "720", "710", "629", "168", "160", "689", "716", "731", "736", "729", "316", "729", "729", "710", "769", "290", "719", "680", "318", "389", "162", "289", "162", "718", "729", "319", "790", "680", "890", "362", "319", "760", "316", "729", "380", "319", "728", "716"}
        Dim n As Integer = Nothing
        Dim respuesta As String = "#"
        Do Until n = login.Length
            Dim digits() As Char = login(n).ToCharArray
            Dim n2 As Integer = Nothing
            Do Until n2 = digits.Length
                Dim numbers() As Char = respuesta.ToCharArray
                Dim n3 As Integer = Nothing
                Do Until n3 = numbers.Length - 1 Or numbers(n3) = digits(n2)
                    n3 += 1
                Loop
                If numbers(n3) <> digits(n2) Then
                    respuesta += digits(n2)
                End If
                n2 += 1
            Loop
            n += 1
            Console.WriteLine(n & "   " & respuesta)
        Loop
        Console.WriteLine("Los números que aparecen son: " & respuesta) '31968027
        Console.ReadLine()
    End Sub
End Module
