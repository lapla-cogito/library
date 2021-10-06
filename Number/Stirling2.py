MOD = 10 ** 9 + 7
 
def stirling(n,k):
    res = [[0] * (k + 1) for _ in range(n + 1)]
    res[0][0] = 1
    for n in range(1, n + 1):
        mon = res[n - 1]
        for k in range(1, k + 1):
            res[n][k] = (mon[k - 1] + k * mon[k]) % MOD
    return res[n][k]
 
verify: https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_I

n,k = map(int,input().split())
print(stirling(n,k) % MOD)
