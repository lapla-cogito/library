#verify: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_2_A

INF = 9e9
v,e = map(int,input().split())
adj = [[INF] * v for _ in range(v)]
dp = [[-1] * v for _ in range(1 << v)]
 
def rec(s,t):
    if s == (1 << v) - 1 and t == 0:
        dp[s][t] = 0
    if dp[s][t] != -1:
        return dp[s][t]
    tmp = INF
    for i in range(v):
        if not (s >> i & 1):
            tmp = min(tmp,adj[t][i] + rec(s | 1 << i,i))
    dp[s][t] = tmp
    return dp[s][t]
 
 
for _ in range(e):
    s,t,d = map(int,input().split())
    adj[s][t] = d
 
res = rec(0,0)
if res == INF:
    res = -1
print(res)
