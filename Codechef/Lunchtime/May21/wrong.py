t = int(input())
for i in range(t):
    n,k=map(int,input().strip().split())
    a = input()
    klist = list(map(int,input().strip().split()))
    c = []
    # print(n,k,a,klist)
    for x in a:
        c.append(int(x))
    d=0
    for x in klist:
        if n==1:
            print(0)
    if n==1:
        continue
    for i in range(1,n):
        if a[i]!=a[i-1]:
            d+=1
        else:
            d+=2

    
    for x in klist:
        
        if x-1==0:
            if c[0]!=c[1]:
                d+=1
            else:
                d-=1          
        elif x-1==n-1:
            if c[x-2]!=c[x-1]:
                d+=1
            else:
                d-=1 
        else:
            if c[x-2]!=c[x-1] and c[x]!=c[x-1]:
                d+=2

            elif c[x-2]==c[x-1] and c[x]==c[x-1]:
                d-=2
            
        print(d)
        c[x-1]^=1



        


