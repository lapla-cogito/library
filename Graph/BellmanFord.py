INF = 998244353
 
def bellman(s,n,adj):
    dist = [INF] * n
    dist[s] = 0
    for i in range(n):
        flag = 0
        for v,e in enumerate(adj):
            for to,cost in e:
                if dist[v] != INF and dist[v] + cost < dist[to]:
                    dist[to] = dist[v] + cost
                    flag = 1
        if not flag:
            break
        elif i == n - 1:
            return [-1]
 
    return dist
        

#verify: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B
 
v,e,r = map(int,input().split())
adj = [[] * v for _ in range(v)]
 
for _ in range(e):
    s,t,d = map(int,input().split())
    adj[s].append((t,d))
 
res = bellman(r,v,adj)
 
if res == [-1]:
        print("NEGATIVE CYCLE")
        exit(0)
 
for i in range(v):
    if res[i] == INF:
        print("INF")
    else:
        print(res[i])
