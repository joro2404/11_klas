
def accumulate_left(lam, n, arr):
    count = len(arr)

    if count == 0 : 
        return n

    else :
        n = lam(n, arr[0])
        arr.pop(0)
        return accumulate_left(lam, n, arr)

def accumulate_right(lam, n, arr):
    count = len(arr)

    if count == 1:
        return lam(arr[-1], n)

    else :
        n = lam(arr[-1], n)
        arr.pop(-1)
        return accumulate_right(lam, n, arr)



print(accumulate_left(lambda a, b: a / b, 64, [2, 4, 8]))
print(accumulate_right(lambda a, b: a / b, 8, [16, 32, 64]))
