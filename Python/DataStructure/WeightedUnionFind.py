class wUnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n + 1)]
        self.rank = [0] * (n + 1)
        self.weight = [0] * (n + 1)
 
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            uku = self.find(self.par[x])
            self.weight[x] += self.weight[self.par[x]]
            self.par[x] = uku
            return uku
 
    def unite(self, x, y, w):
        xx = x
        yy = y
        x = self.find(x)
        y = self.find(y)
        w -= self.weight[xx]
        w += self.weight[yy]
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
            self.weight[x] = w
        else:
            self.par[y] = x
            self.weight[y] = -w
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1
 
    def issame(self, x, y):
        return self.find(x) == self.find(y)
 
    def diff(self, x, y):
        if self.find(x) != self.find(y):
            return "?"
        return self.weight[y] - self.weight[x]

'''verify: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
 
 
n, q = map(int, input().split())
uf = wUnionFind(n)
for _ in range(q):
    li = list(map(int, input().split()))
    if not li[0]:
        uf.unite(li[1], li[2], li[3])
    else:
        print(uf.diff(li[2], li[1]))
'''