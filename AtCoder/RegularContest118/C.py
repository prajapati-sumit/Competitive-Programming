
pi=1
p=13
a=4
b=5
for i in range(p):
    print(pi,end=" ")
    if i!=p-1 and (pi*a)%p==1:
        pi=(pi*b)%p
    pi=(pi*a)%p

# a^12 

