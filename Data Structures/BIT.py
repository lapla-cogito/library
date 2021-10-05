class BIT:
    def __init__(self,n):
        self.s = n
        self.li = [0] * (self.s + 1)
 
    def update(self,k,x):
        while k <= self.s:
            self.li[k]+=x
            k+=k & -k
 
    def _query(self,n):
        res = 0
        while n > 0:
            res+=self.li[n]
            n-=n & -n
        return res
 
    def query(self,s,t):
        return self._query(t) - self._query(s)

#verify: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
 
n,q = map(int,input().split())
bit = BIT(n)
for _ in range(q):
    c,a,b = map(int,input().split())
    if c:
        print(bit.query(a - 1,b))
    else:
        bit.update(a,b)
