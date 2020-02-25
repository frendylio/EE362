def circle(x, y, r, RecursionLoopX = 0, SkipZero = False):
    L = []
    RadioMaximo = r**2
    CoordinateX = (x - r)
    if RecursionLoopX == 0 and SkipZero == False:
        RecursionLoopX = CoordinateX

    #Symetry of a circle loop only for Y 
    L = [
        (RecursionLoopX, CoordinateY) 
        for CoordinateY in range (y-r, y+r+1) 
        if (CoordinateY - y)**2 + (RecursionLoopX - x)**2  <= RadioMaximo
        ]

    if RecursionLoopX <= x + r:
        print(L)
        RecursionLoopX = RecursionLoopX + 1
        SkipZero = True
        circle(x,y,r, RecursionLoopX, True)
    return []

# Do not change this.
def display_list(L):
    quotient = len(L)//5
    remainder = len(L)%5
    for i in range(quotient):
        print(L[i*5:(i+1)*5])
    if remainder > 0:
        print(L[quotient*5:quotient*5+remainder])


#print(circle(0,0,3))
print('Circle centered at (0,0) and radius 3')
display_list(circle(0,0,3))
print(' ')
print('Circle centered at (-2,1) and radius 4')
display_list(circle(-2,1,4))
