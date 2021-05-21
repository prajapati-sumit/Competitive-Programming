from math import ceil

k,n,m=map(int, input().split())
a=list(map(int, input().split()))

counter=0
sorted(a)

b=[]
cnt=0
for i in range(k-1):
    here=(m*a[i])//n
    cnt+=here
    b.append(here)

b.append(m-cnt)

res=0
print(a)
for i in range(k):
    res=max(res, abs(a[i]/n-b[i]/m))
    print(b[i],end=" ")

