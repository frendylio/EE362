
def reverse_int(n):
    """ Returns the reverse of the digits of n """
    # Declare variables
    is_Negative = 0
    Reverse = 0

    # primero checkea si es negativo
    # si es, make is_Negative true and multiply n -1 so the loop works
    if n < 0:
        is_Negative = 1
        n = n * (-1)

    # Loop reverse
    while(n > 0):
        Sobra = n % 10 # consigue la sobra de la fraction
        Reverse = (Reverse * 10) + Sobra # so it goes X X 1 -> X 1 0 -> 1 0 1
        n = n // 10 # consigue el siguiente numero

    # do this because we want to return n 
    n = Reverse 

    # if n es negativo ponle negative.
    if is_Negative == 1:
        n = n * (-1)
    return n



print("n = ", 456, ", reverse = ", reverse_int(456))
print("n = ", -456, ", reverse = ", reverse_int(-456))
print("n = ", 3400, ", reverse = ", reverse_int(3400))
