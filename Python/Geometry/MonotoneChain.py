def crossp(a,b,c):
    return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])
 
def graham(li):
    temp = []
    for i in li:
        temp.append([i[1],i[0]])
    temp.sort()
 
    res = []
    for i in temp:
        while len(res) > 1 and crossp(res[-1],res[-2],i) > 0:res.pop()
        res.append(i)
    mon = len(res)
    for i in range(len(temp) - 2,-1,-1):
        uku = temp[i]
        while len(res) > mon and crossp(res[-1],res[-2],uku) > 0:res.pop()
        res.append(uku)
    for i in range(len(res) - 1,0,-1):
        res[i][0],res[i][1] = res[i][1],res[i][0]
    res.reverse()
    return res[:-1]

'''verify: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A
 
n = int(input())
li = []
for _ in range(n):
    x,y = map(int,input().split())
    li.append((x,y))
 
res = graham(li)
print(len(res))
for i in res:print(*i)
'''