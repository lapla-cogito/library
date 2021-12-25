def inv(a):
    n=len(a)
    I=[[0 if i!=j else 1 for i in range(n)] for j in range(n)]
    print(I)
    if n!=len(a[0]): return None
    for i in range(n):
        ma=abs(a[i][i])
        loc=i
        for j in range(i+1,n):
            mon=abs(a[j][i])
            if ma<mon:
                ma=mon
                loc=j
        if loc!=i:
            for j in range(n):
                temp=a[loc][j]
                a[loc][j]=a[i][j]
                a[i][j]=temp
                temp=I[loc][j]
                I[loc][j]=I[i][j]
                I[i][j]=temp
        gain=1/a[i][i]
        for j in range(n):
            a[i][j]*=gain
            I[i][j]*=gain
        for j in range(n):
            if i!=j:
                gain=a[j][i]
                for k in range(n):
                    a[j][k]-=a[i][k]*gain
                    I[j][k]-=I[i][k]*gain
    return I