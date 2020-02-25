



def bitcount1(n):
    count1 = 0
    for i in range(32):
        count1 += (n >> i)&1
    return count1

def bitcount2(n):
    count2 = 0
    leftOverBits = n
    while leftOverBits:
        count2 += 1
        leftOverBits = leftOverBits & (leftOverBits - 1)
    return count2

def bitcount3(n):
    count3 = 0
    leftOverBits = n
    table = [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4]
    for i in range(16):
        count3 += table[leftOverBits & 0xf]
        leftOverBits = leftOverBits >> 4
    return count3

def bitcount4(n):
    m = n
    mask1 = 0x55555555   # Change this mask
    mask2 = 0x33333333  # Change this mask
    mask3 = 0x0F0F0F0F  # Change this mask
    mask4 = 0x00FF00FF   # Change this mask
    mask5 = 0x0000FFFF # Change this mask
    m = (mask1 & m) + (mask1 & (m >> 1))
    m = (mask2 & m) + (mask2 & (m >> 2))
    m = (mask3 & m) + (mask3 & (m >> 4))
    m = (mask4 & m) + (mask4 & (m >> 8))
    m = (mask5 & m) + (mask5 & (m >> 16))
    return m 

    # 0101 0101 0101 0101 0101 0101 0101 0101

    # 0011 0011 0011 0011 0011 0011 0011 0011

    # 0000 1111 0000 1111 0000 1111 0000 1111

    # 0000 0000 1111 1111 0000 0000 1111 1111

    # 00000 0000 0000 0000 1111 1111 1111 1111 

k = 0xfffFFFFF
print(bitcount1(k))
print(bitcount2(k))
print(bitcount3(k))
print(bitcount4(k))

