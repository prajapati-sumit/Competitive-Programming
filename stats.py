
inf = 1e9


try:
    a = []  
    while True:
        a.append(list(map(int,input().strip().split())))
except:
    pass

n = len(a)
m = len(a[0])


for i in range(n):
    cur = max(a[i])
    cnt = 0
    for k in range(m):
        cnt+=(a[i][k] ==cur)
    if(cnt>1):
        print("-1")
        exit(0)

    cur = min(a[i])
    cnt = 0
    for k in range(m):
        cnt+=(a[i][k] ==cur)
    if(cnt>1):
        print("-1")
        exit(0)
 
for j in range(m):
    cur = -inf
    for i in range(n):
        cur = max(cur,a[i][j])
    cnt = 0
    for i in range(n):
        cnt+=(a[i][j] ==cur)
    if(cnt>1):
        print("-1")
        exit(0)

    cur = inf
    for i in range(n):
        cur = min(cur,a[i][j])

    cnt = 0
    for i in range(n):
        cnt+=(a[i][j] ==cur)
    if(cnt>1):
        print("-1")
        exit(0)

cnt=0
for i in range(n):
    for j in range(m):
        if(max(a[i])==a[i][j] or min(a[i])==a[i][j]):
            cnt+=1
        else:
            cur = -inf
            for k in range(n):
                cur = max(cur,a[k][j])

            if(a[i][j]==cur):
                cnt+=1
            else:
                cur = inf
                for k in range(n):
                    cur = min(cur,a[k][j])
                if(a[i][j]==cur):
                    cnt+=1
        # print(i,j,a[i][j],cnt)

print(cnt);