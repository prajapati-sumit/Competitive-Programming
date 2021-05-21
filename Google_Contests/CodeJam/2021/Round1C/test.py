A=["Table","Pen","Laptop","Mobile","Book"]
W=[20,0.02,2,0.2,1]

big=0
small=0
n=len(A)

for i in range(n):
    if W[i]>W[big]:
        big=i
    if W[i]<W[small]:
        small=i

print("Max:",A[big])
print("Min:",A[small])