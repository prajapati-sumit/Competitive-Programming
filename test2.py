def distance(a):
    l = len(a)
    d = 0
    for i in range(1,len(a)):
        if a[i]!=a[i-1]:
            d+=1
        else:
            d+=2
    return d
def listupdate(a,x):
        if a[x-1]>0:
            a[x-1]-=1
        else:
            a[x-1]+=1
        return a
# print(distance([0,1,0,0,1]))
t = int(input())
for i in range(t):
    [n,k]=list(map(int,input().strip().split()))
    a = input()
    klist = list(map(int,input().strip().split()))
    c = []
    
    for x in a:
        c.append(int(x))
    d = distance(c)
    # print(d)
    for x in klist:
        if x-1==0:
            if c[0]!=c[1]:
                d+=1
                print(d)

            else:
                d-=1
                print(d)
            c = listupdate(c,x-1)

        elif x-1==n-1:
            if c[x-2]!=c[x-1]:
                d+=1
                print(d)
            else:
                d-=1
                print(d)
            c = listupdate(c,x-1)
        else:
            if c[x-2]!=c[x-1] and c[x]!=c[x-1]:
                d+=2
                print(d)
            elif c[x-2]!=c[x-1] and c[x]==c[x-1]:
                print(d) 
            elif c[x-2]==c[x-1] and c[x]!=c[x-1]:
                print(d)
            elif c[x-2]!=c[x-1] and c[x]!=c[x-1]:
                d-=2
                print(d)
            c = listupdate(c,x-1)