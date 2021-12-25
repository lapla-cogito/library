def plus(a,b):
    res=[]
    for i in range(len(a)):
        temp=[]
        for j in range(len(a[i])):
            temp.append(a[i][j]+b[i][j])
        res.append(temp)
    return res