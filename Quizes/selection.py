def selection(L):

    # Para todos los indexes
    for LoopIndexes in range(len(L)): 
        
        IndexMin = LoopIndexes

        for LoopMin in range(LoopIndexes+1, len(L)): 
            if L[IndexMin] > L[LoopMin]: 
                IndexMin = LoopMin 
                
        # Cambia el IndexMin with the LoopIndexes 
        temp = L[LoopIndexes]
        L[LoopIndexes] = L[IndexMin]
        L[IndexMin] = temp


    return L

L = [15, 6, 33, 2, 11, 7, 3, 20, 18, 12, 4, 9, 3, -1, 0]


print("Initial Raw List:", L)
print("Sorted List:", selection(L))
