MOD = 1e9 + 7
 
def mul(a,b):
    aa = len(a)
    bb = len(b[0])
    if not aa == len(b):return None
    res = [[0] * bb for _ in range(aa)]
    for i in range(aa):
        for j in range(bb):
            for k in range(len(b)):
                res[i][j] += a[i][k] * b[k][j]
                res[i][j]%=MOD
    return res
 
def matPow(a,n):
    s = len(a)
    res = [[0] * s for _ in range(s)]
    for i in range(s):
        res[i][i] = 1
    while n > 0:
        if n & 1:res = mul(res,a)
        a = mul(a,a)
        n>>=1
    return res

'''verify: https://yukicoder.me/problems/no/526
 
n,m = map(int,input().split())
MOD = m
a = [[1,1],
     [1,0]]
res = mul(matPow(a,n - 1),[[1],
                           [0]])
print(int(res[1][0]))
'''