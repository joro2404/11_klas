def max_notes(p):
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

print(max_notes([[1, 2, 3], [2, 2, 2], [9, 7, 3]]))
print(leading([[2, 10, 2], [2, 22, 22], [9, 7, 3]]))