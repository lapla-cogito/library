#verify: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_2_B

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
 
v,e = map(int,input().split())
adj = [[INF] * v for _ in range(v)]
deg = [0] * v
cost = 0
 
for _ in range(e):
    s,t,d = map(int,input().split())
    adj[s][t] = min(d,adj[s][t])
    adj[t][s] = adj[s][t]
    deg[s]+=1
    deg[t]+=1
    cost+=d
 
for i in range(v):
    adj[i][i] = 0
 
res = warshall(v,adj)
oddli = [i for i in range(v) if deg[i] % 2]
length = len(oddli)
dp = [INF] * (1 << length)
dp[0] = 0
for i in range(1 << length):
    for j in range(length):
        if not i & (1 << j):
            for k in range(j + 1,length):
                if not i & (1 << k):
                    dp[i | 1 << j | 1 << k] = min(dp[i | 1 << j | 1 << k],dp[i] + res[oddli[j]][oddli[k]])
print(cost + dp[(1 << length) - 1])
