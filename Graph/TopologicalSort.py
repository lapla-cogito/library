#verify: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B

res = []
visited = []
def dfs(n,adj):
    global visited
    visited[n] = 1
    for i in adj[n]:
        if not visited[i]:dfs(i,adj)
    res.append(n)
 
def tsort(n,adj):
    for i in range(n):
        if not visited[i]:dfs(i,adj)
    res.reverse()
    return res
 
v,e = map(int,input().split())
visited = [0] * v
adj = [[] * v for _ in range(v)]
for _ in range(e):
    s,t = map(int,input().split())
    adj[s].append(t)
 
res = tsort(v,adj)
for i in res:print(i)
