class LCA:
    def __init__(self, g, root=0):
        self.root = root
        self.g = g
        self.depth = [-1 if i != self.root else 0 for i in range(len(self.g))]
        self.uku = (len(self.g) - 1).bit_length()
        self.par = [[-1] * len(self.g) for _ in range(self.uku)]
        que = [self.root]
        while que:
            u = que.pop()
            for i in self.g[u]:
                if self.depth[i] == -1:
                    self.depth[i] = self.depth[u] + 1
                    self.par[0][i] = u
                    que += [i]

        for i in range(1, self.uku):
            for j in range(len(self.g)):
                if self.par[i - 1][j] != -1:
                    self.par[i][j] = self.par[i - 1][self.par[i - 1][j]]

    def query(self, u, v):
        if self.depth[v] < self.depth[u]:
            u, v = v, u
        for i in range(self.uku):
            if self.depth[v] - self.depth[u] >> i & 1:
                v = self.par[i][v]
        if u == v:
            return u
        for i in range(self.uku - 1, -1, -1):
            uu, vv = self.par[i][u], self.par[i][v]
            if uu != vv:
                u, v = uu, vv
        return self.par[0][u]

'''verify: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
n = int(input())
g = [[] for _ in range(n)]
for i in range(n):
    li = list(map(int, input().split()))
    for j in range(li[0]):
        g[i] += [li[j + 1]]

l = LCA(g)
q = int(input())
for _ in range(q):
    u, v = map(int, input().split())
    print(l.query(u, v))
'''