

for tt in range(int(input())):
    s1=input()
    s2=input()
    n1=len(s1)
    n2=len(s2)
    flag=False
    for i in range(1,30):
        if (i*n1)%n2==0 :
            here1=s1*i
            here2=s2*((i*n1)//n2)
            if here1==here2:
                flag=True
                print(here1)
                break
    if not flag:
        print(-1)
