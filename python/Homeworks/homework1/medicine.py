def is_stronger(a, b):
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


def least_stronger(a, arr):
    least = 0
    best = ()
    curr_of_a = 0
    for j in a[1]:
        curr_of_a += j[1]

    for i in arr :
        if is_stronger(i,a):
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

def strong_relation(l):
    res = []
    for i in l:
        lst = []
        curr = ()
        for j in l:
            if is_stronger(j ,i) and i != j:
                lst.append(j[0])
                
        curr = (i, lst)
        
        res.append(curr)

    return res


A = ("A", [("p",5), ("q", 3), ("t", 1)])
B = ("B", [("p",4), ("q", 3)])
C = ("C", [("p",3)])
D = ("D", [("p",5), ("q", 3), ("t", 2)])

print(is_stronger(A,B))
print(is_stronger(A,C))
print(is_stronger(C, A))
print(is_stronger(D ,A))

print(least_stronger(B, [A, C, D]))

l = [A, B, C, D]
strong_relation(l)