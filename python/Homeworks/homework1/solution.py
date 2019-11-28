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

def isStronger(a, b):
    a_names_and_quantity = {}
    b_names_and_quantity = {}
    counter = 0

    for i in range(len(a[1])):
        a_names_and_quantity[a[1][i][0]] = []
        a_names_and_quantity[a[1][i][0]] = a[1][i][1]

    for i in range(len(b[1])):
        b_names_and_quantity[b[1][i][0]] = []
        b_names_and_quantity[b[1][i][0]] = b[1][i][1]

    if len(b) > len(a):
        return False

    for i in a_names_and_quantity:
        for j in b_names_and_quantity:
            if i == j :
                if a_names_and_quantity[i] >= b_names_and_quantity[j]:
                    counter += 1
                    continue
                else : 
                    return False

    if counter < len(b_names_and_quantity):
        return False

    return True


def leastStronger(a, arr):
    least = 0
    best = ()
    curr_of_a = 0
    for j in a[1]:
        curr_of_a += j[1]

    for i in arr :
        if isStronger(i,a):
            curr = 0
            for j in a[1]:
                for p in i[1]:
                    if j[0] == p[0]:
                        curr += p[1]

            curr -= curr_of_a
            if least == 0:
                least = curr
            if curr <= least:
                least = curr
                best = i
            
    if least == 0:
        return []

    return best

def strongRelation(l):
    res = []
    for i in l:
        lst = []
        curr = ()
        for j in l:
            if isStronger(j ,i) and i != j:
                lst.append(j[0])
                
        curr = (i, lst)
        
        res.append(curr)

    return res

def maxNotes(p):
    res = 0

    for i in p:
        if sum(i) > res:
            res = sum(i)

    return res

def leading(p):
    lst = []
    maxx = 0
    index = 0

    for i in range(0, len(p[1])):
        for j in range(0, len(p)):
            if p[j][i] > maxx:
                maxx = p[j][i]
                index = j

        lst.append(index)
        maxx = 0
        index = 0

    print(lst)
    return max(set(lst), key=lst.count)