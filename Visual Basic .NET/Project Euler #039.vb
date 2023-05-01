Module Module1
    Sub Main()
        'El programa busca la cantidad de lados de un triángulo recto con un perímetro determinado
        Dim teorema As Boolean = False
        Dim suma As Boolean = False
        Dim a As Integer = 1
        Dim b As Integer = 1
        Dim c As Integer = 1
        Dim p As Integer = 120
        Dim soluciones As Integer = 0
        Dim maxsoluciones As Integer = 0
        Dim respuesta As Integer = 0
        Do Until p > 1000
            'La suma de los lados tiene que ser igual al perímetro
            'Y la suma de los cuadrados de los catetostiene que ser igual a la hipotenusa
            suma = (a + b + c = p)
            teorema = (a ^ 2 + b ^ 2 = c ^ 2)
            'Se busca números conociendo las condiciones previas y que a > b > c
            If a = p Or a > b Then
                a = 1
                b += 1
            ElseIf b = p Or b > c Then
                b = 1
                c += 1
            ElseIf c = p Then 'Se buscan perímetros múltiplos de 60
                p += 60
                soluciones = 0
                a = 1
                b = 1
                c = 1
                Console.Write(a & "   " & b & "   " & c & "   " & soluciones & "   " & maxsoluciones & "   " & p & "   " & respuesta)
            Else
                a += 1
            End If
            'La cantidad de soluciones aumenta cuando tanto el teorema como la suma se obedecen; imprime números conseguidos.
            If teorema = True And suma = True Then
                soluciones += 1
                Console.WriteLine(a & "   " & b & "   " & c & "   " & soluciones & "   " & maxsoluciones & "   " & p & "   " & respuesta)
            End If
            'La respuesta es el perímetro que ofrezca más soluciones
            If soluciones > maxsoluciones Then
                maxsoluciones = soluciones
                respuesta = p
            End If
        Loop
        Console.Write("La respuesta es ")
        Console.WriteLine(respuesta)
        Console.ReadLine()
    End Sub
End Module
