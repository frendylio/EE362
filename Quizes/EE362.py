n = int(input("Enter integer: "))
if n < 0:
    print("Not a power of 2")
else:
    #In bits, power of 2 are like
    # 1000....0
    
    # If we substract -1 then
    # 01111....1
    nMinusOne = n -1

    # If we AND(&) n and nMInusOne, it will give 0
    # 100...0 & 011...1 = 0
    isPowerTwo = n & nMinusOne

    #if n = 0 then no power of 2
    if n == 0:
        print("Is not a Power of 2")
    #if isPowerTwo = 0 Then is Power of 2
    elif isPowerTwo == 0:
        print("Is a power of 2")
    else:
        print("Is not a Power of 2")
    
