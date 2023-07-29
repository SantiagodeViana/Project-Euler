Module Module1
    Sub Main()
        Dim n As Long = 100000000
        Do 'Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0
            Dim nword As String = n.ToString
            n += 10
            Dim respuesta As String = (n ^ 2).ToString
            'If respuesta.Substring(0, 1) = 1 And respuesta.Substring(3, 1) = 2 Then
            '    Console.WriteLine(n & "   " & respuesta)
            'End If
            If respuesta.Length > 20 Then
                If respuesta.Substring(0, 1) = 1 And respuesta.Substring(3, 1) = 2 And respuesta.Substring(5, 1) = 3 And respuesta.Substring(7, 1) = 4 And respuesta.Substring(9, 1) = 5 And respuesta.Substring(11, 1) = 6 And respuesta.Substring(13, 1) = 7 And respuesta.Substring(15, 1) = 8 And respuesta.Substring(17, 1) = 9 Then
                    Console.WriteLine("La respuesta es " & n)
                    Console.ReadLine()
                    End
                End If
            End If
        Loop
    End Sub
End Module
