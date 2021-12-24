INF = 10 ** 9
 
def levenshtein(s,t):
    slen = len(s)
    tlen = len(t)
    li = [[INF] * (tlen + 1) for _ in range(slen + 1)]
 
    for i in range(slen + 1):
        li[i][0] = i
    for i in range(tlen + 1):
        li[0][i] = i
 
    for i in range(slen):
        for j in range(tlen):
            cost = 0 if s[i] == t[j] else 1
            li[i + 1][j + 1] = min(li[i][j + 1] + 1,li[i + 1][j] + 1,li[i][j] + cost)
    return li[slen][tlen]

'''verify: https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E
 
s = input()
t = input()
print(levenshtein(s,t))
'''