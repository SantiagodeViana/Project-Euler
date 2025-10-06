def is_step_number(n): # Comprueba si n es un "step number", donde todos los dígitos consecutivos tienen una diferencia de uno entre sí mismos
    step = 1 # Step es una variable booleana.
    if n < 10:
        step = 0 # Se declarán los n de un sólo dígito como no step number
    else:
        aux = n % 10 # Aux almacena el dígito anterior
        n //= 10
        while step == 1 and n > 0:
            if (n % 10 != (aux + 1) and n % 10 != (aux - 1)):
                step = 0  # Se comprueba que haya una diferencia de uno entre los dígitos
            aux = n % 10
            n //= 10
    return step
