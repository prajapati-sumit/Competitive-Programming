
#For storing the path
stack=[]
def recursion(x,y,m,n):
    #End of the path
    if x==m and y==n:
        stack.append((x,y))
        for x in stack:
            print(x,end=" ")
        print()
        stack.pop()
        return
    #Out of Grid
    if x>m or y>n:
        return
    
    stack.append((x,y))
    recursion(x+1,y,m,n)   #Go RIGHT
    recursion(x,y+1,m,n)   #Go UP
    stack.pop()



def iterative(x,y,m,n):
    cur=[(1,1)]
    stack.append(cur)
    while len(stack):
        
        # print(stack)
        top=stack[-1]
        stack.pop()
        
        lx=top[-1][0]
        ly=top[-1][1]
        if lx==m and ly==n:
            print(top)
            continue
        if lx<m:
            stack.append(top+[(lx+1,ly)])
        if ly<n:
            stack.append(top+[(lx,ly+1)])
       

m=2
n=2
recursion(1,1,m,n)
iterative(1,1,m,n)
