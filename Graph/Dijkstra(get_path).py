from heapq import heappush, heappop
INF = 998244353
 
def dijkstra(s,n,adj):
    dist = [INF] * n
    global prev
    prev = [-1] * n
    dist[s] = 0
    h = [(0,s)]
 
    while h:
        d,v = heappop(h)
        if d > dist[v]:
            continue
 
        for to,cost in adj[v]:
            if dist[v] + cost < dist[to]:
                dist[to] = dist[v] + cost
                prev[to] = v
                heappush(h,(dist[to],to))
    return dist
 
def get_path(g):
    path = []
    while g != -1:
        path.append(g)
        g = prev[g]
    path.reverse()
    return path
