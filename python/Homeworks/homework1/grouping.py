def group_by_f(f, lst):
    dct = {}
        
    for i in range(0, len(lst)):
        if f(lst[i]) not in dct :
            dct[f(lst[i])] = []
            
    for i in dct:
        for j in range(0, len(lst)):
            if f(lst[j]) == i : #zashto ne raboti dct[i] ?
                dct[i].append(lst[j])

    return dct


print(group_by_f(lambda a : a%2 == 0, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
print(group_by_f(len, [[1], [7, 8], [1, 2, 3, 4], [4], ["random", "words"]]))
