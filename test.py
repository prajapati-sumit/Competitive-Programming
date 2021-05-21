


n=3
m=3

#using List as a stack
stack=[]
#Starting Position
cur=[1,1,0]
t=25
while t:
    t-=1    
    
    if cur[0]<=m and cur[1]<=n and cur[2]<2:
        cur[2]+=1
        print(cur)
        stack.append(cur)
        # if cur[0]==m and cur[1]==n:
        #     for x in stack:
        #         print(x,end=" ")
        #     print()
        cur = [cur[0]+1,cur[1],0]

    elif(stack):
        cur = stack[-1]
        if (cur[0]==m and cur[1]==n) or cur[2]==2:
            stack.pop()
        else:
            cur = [cur[0],cur[1]+1,0]
       
        
    else:
        break
      
