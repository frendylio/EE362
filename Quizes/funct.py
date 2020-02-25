#does not run if negative number on first spot
def multiply(m,n):
    product = 0
    num1, num2 = m, n

    if m < 0: # fix negatigve number issue with m
        num1 = (-1) * num1

    while num1 != 0:
        if num1 & 1 == 1:
            product += num2
        num2 = num2 << 1
        num1 = num1 >> 1

    if m < 0: # if m is < 0 make product x (-1)
        product = product * (-1) 
    return product

def bin2dec(s):

    # initilize dec
    dec = 0
    # bit position
    bit_position = -1
    
    for i in range(len(s)-1, -1, -1):
        bit_position = bit_position + 1
        bit_value = int(s[i]) 
        dec = dec + bit_value * 2**(bit_position)
    return dec

def dec2bin(n):
    #binary
    binary_string = []
    binary = ''
    is_negative = 0 
    # if n < 0 make it positive and add -
    if n < 0:
        is_negative = 1
        n = (-1)*n 

    # get binary not correct order 
    while n != 0:
        reminder = n%2
        n = n//2 #returns integer 
        binary_string.append(reminder)
    
    #Reverse order
    for item in reversed(binary_string):
        binary = binary + str(binary_string[item])

    # if n was negative add - 
    if is_negative == 1:
        binary = str("-") + binary
    return binary

k = multiply(7, 5)
print("Multiply 7x5 =", k)

k = multiply(-7, 5)
print("Multiply -7x5 =", k)

k = multiply(7, -5)
print("Multiply 7x-5 =", k)

k = multiply(-7, -5)
print("Multiply -7x-5 =", k)

s = "100101"
n = bin2dec(s)
print("Decimal value of", s, "=", n)

s = "11001010"
n = bin2dec(s)
print("Decimal value of", s, "=", n)


n = 30
s = dec2bin(n)
print("Binary string of", n, "=", s)

n = -30
s = dec2bin(n)
print("Binary string of", n, "=", s)


