a = [6, 7, 8, 4, 2, 4, 5, 8, 6, 3, 1, 2, 4]
hist = {}

for i in a:
    if i in hist:
        hist[i] += 1
    else :
        hist[i] = 1

print(hist)

