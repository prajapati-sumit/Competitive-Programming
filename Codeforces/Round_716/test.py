from math import gcd

def newf(i):
    i2,i3,i4,i6=i//2,i//3,i//4,i//6
    if gcd(i6,gcd(i2,gcd(i3,i4)))>=7:
        print(i2,i3,i4,i6,"->",i," -",i//5)
        return True
    return False

def newf2(i):
    i1,i5=i//1,i//5
    if gcd(i1,i5)>=7:
        print(i1,i5,"->",i)
        return True
    return False

for i in range(1,501):
    if  newf(i):
        break


for i in range(1,501):
    if  newf2(i):
        break

a=[77,24,39,89,60]
base=(2**7)
def encode():
    res=0
    cur=1
    for el in a:
        res+=cur*el
        cur*=base
    return res
def decode(x):
    res=[]
    while x:
        res.append(x%base)
        x//=base
    print(res) 

decode(encode())
# on day 84: 
# day-1 : 2^42 *R1
# day-2 : 2^48 *R2
# day-1 : 2^42 *R1
# day-1 : 2^42 *R1
# day-1 : 2^42 *R1
# day-1 : 2^42 *R1
