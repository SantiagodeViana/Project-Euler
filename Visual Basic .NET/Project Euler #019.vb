Module Module1
    Sub Main()
        ' Solución para el problema #19 de Project Euler
        ' "¿Cuántos domingos cayeron en primero de mes durante el siglo XX (del 1 de enero de 1901 al 31 de diciembre de 2000)?"
        ' https://projecteuler.net/problem=19
        ' Código espagueti de 2016; optimizar
    
        Dim year As Integer = 1901
        Dim month As Integer = 1
        Dim week As Integer = 2
        Dim days As Integer = 1
        Dim respuesta As Integer = Nothing
        Do Until year > 2000 'Busca los domingos que sean el primer día en cada mes del siglo XXI
            If week > 7 Then 'Una semana tiene 7 días
                week = 1
            End If
            If days > 31 Then 'Los meses tienen 31 días
                days = 1
                month += 1
                If month > 12 Then 'Un año tiene 12 meses
                    month = 1
                    year += 1
                End If
            ElseIf days > 30 And month = 4 Or days > 30 And month = 6 Or days > 30 And month = 9 Or days > 30 And month = 11 Then 'Abril, junio, septiembre y noviembre tienen 30 días
                days = 1
                month += 1
            ElseIf days > 29 And month = 2 And year Mod 4 = 0 Then 'Los días bisiestos tienen un día más
                If year Mod 400 = 0 Then
                    days = 1
                    month += 1
                End If
            ElseIf days > 28 And month = 2 Then 'febrero tiene 28 días
                days = 1
                month += 1
            End If
            If week = 7 And days = 1 Then 'Si un domingo es el primer día del mes
                respuesta += 1 'Se agrega a la respuesta
                Console.WriteLine(year & "   " & month & "   " & week & "   " & days & "   " & respuesta)
            End If
            days += 1
            week += 1
        Loop
        Console.Write("La respuesta es " & respuesta) 'La respuesta es 171
        Console.ReadLine()
    End Sub
End Module
