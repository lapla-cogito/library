from heapq import heappush, heappop
INF = 998244353
 
def dijkstra(s,n,adj):
    dist = [INF] * n
    dist[s] = 0
    h = [(0,s)]
 
    while h:
        d,v = heappop(h)
        if d > dist[v]:
            continue
 
        for to,cost in adj[v]:
            if dist[v] + cost < dist[to]:
                dist[to] = dist[v] + cost
                heappush(h,(dist[to],to))
    return dist
 
'''verify: https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_f

n,k = map(int,input().split())
adj = [[] * n for _ in range(n)]
 
for i in range(k):
    l = list(map(int,input().split()))
    if l[0] == 0:
        res = dijkstra(l[1] - 1,n,adj)
        if res[l[2] - 1] == INF:
            print(-1)
        else:
            print(res[l[2] - 1])
    else:
        adj[l[1] - 1].append((l[2] - 1,l[3]))
        adj[l[2] - 1].append((l[1] - 1,l[3]))
'''