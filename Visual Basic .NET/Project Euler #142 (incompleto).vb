Module Module1

    Sub Main()

        Dim x As Integer = 3
        Dim y As Integer = 2
        Dim z As Integer = 1
        Dim square1 As Double = Nothing
        Dim square2 As Double = Nothing
        Dim square3 As Double = Nothing
        Dim square4 As Double = Nothing
        Dim square5 As Double = Nothing
        Dim square6 As Double = Nothing
        Dim perfect1 As Boolean = False
        Dim perfect2 As Boolean = False
        Dim perfect3 As Boolean = False
        Dim perfect4 As Boolean = False
        Dim perfect5 As Boolean = False
        Dim perfect6 As Boolean = False
        Dim respuesta As Long = Nothing
        Dim limite As Integer = 100000

        'Find the smallest x + y + z with integers x > y > z > 0 such that x + y, x − y, x + z, x − z, y + z, y − z are all perfect squares.

        Do Until perfect1 And perfect2 = True And perfect3 And perfect4 And perfect5 And perfect6 = True

            square1 = Math.Sqrt(x + y)
            square2 = Math.Sqrt(x - y)
            square3 = Math.Sqrt(x + z)
            square4 = Math.Sqrt(x - z)
            square5 = Math.Sqrt(y + z)
            square6 = Math.Sqrt(y - z)
            perfect1 = square1 Mod 1 = 0
            perfect2 = square2 Mod 1 = 0
            perfect3 = square3 Mod 1 = 0
            perfect4 = square4 Mod 1 = 0
            perfect5 = square5 Mod 1 = 0
            perfect6 = square6 Mod 1 = 0
            respuesta = x + y + z

            x += 1

            If x > limite Then
                y += 1
                x = y + 1

                Console.Write(x)
                Console.Write("   ")
                Console.Write(y)
                Console.Write("   ")
                Console.Write(z)
                Console.Write("   ")
                Console.Write(perfect1)
                Console.Write("   ")
                Console.Write(perfect2)
                Console.Write("   ")
                Console.Write(perfect3)
                Console.Write("   ")
                Console.Write(perfect4)
                Console.Write("   ")
                Console.Write(perfect5)
                Console.Write("   ")
                Console.Write(perfect6)
                Console.WriteLine("   ")

            End If

            If y > limite Then
                z += 1
                y = z + 1
            End If

            If z > limite Then
                limite = limite + 1000
            End If

        Loop

        Console.Write("La respuesta es ")
        Console.Write(respuesta)
        Console.ReadLine()

    End Sub

End Module
