


def printxor(n):
    res=0
    for i in range(1,n):
        print(i,"^",end=" ")
        res^=i
    res^=n
    print(n,"=",res)

for i in range(1,16):
    printxor(i)