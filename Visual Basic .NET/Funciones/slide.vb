'Función usada en Project Euler #28

Dim respuesta As Integer = 1
Dim n As Integer = 1
Dim move As Integer = Nothing

'Suma todas las líneas diagonales en un espiral de 1001 x 1001
Function slide()
    n += move
    respuesta = respuesta + n
    Console.WriteLine(n & "   " & move & "  " & respuesta)
End Function
