a = input().split(' ')


for i in range(0, len(a)) :
    if a[i] =='\'' : 
        for j in range(i, len(a)):
            if i != j and a[j] == '\'':
                a.pop(a[i])
                a.pop(a[i])

    if a[i] =='(' : 
        for j in range(i, len(a)):
            if  a[j] == ')':
                a.pop(a[i])
                a.pop(a[i])
        
    if a[i] =='[' : 
        for j in range(i, len(a)):
            if a[j] == ']':
                a.pop(a[i])
                a.pop(a[i])

    if a[i] =='{' :
        for j in range(i, len(a)):
            if a[j] == '}':
                a.pop(a[i])
                a.pop(a[i])

print(a)