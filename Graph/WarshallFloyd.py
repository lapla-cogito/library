INF = 9e9
 
def warshall(n,dis):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dis[i][k] != INF and dis[k][j] != INF:
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j])
 
    if any(dis[i][i] < 0 for i in range(n)):
        return [-1]
 
    return dis
 
#verify: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C

v,e = map(int,input().split())
adj = [[INF] * v for _ in range(v)]
 
for _ in range(e):
    s,t,d = map(int,input().split())
    adj[s][t] = d
 
for i in range(v):
    adj[i][i] = 0
 
res = warshall(v,adj)
 
if res == [-1]:
        print("NEGATIVE CYCLE")
        exit(0)
 
for i in range(v):
    li = []
    for j in range(v):
        if res[i][j] == INF:
            li.append("INF")
        else:
            li.append(str(res[i][j]))
    li = ' '.join(li)
    print(li)
