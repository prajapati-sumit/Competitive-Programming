

def implies(p,q):
    return (not p) or q

def ques(p,q,r):

    return implies(p,q) and implies(q,r)

def op1(p,q,r):

    return implies(p and q,r)

def op2(p,q,r):

    return implies(q and r,p)

def op3(p,q,r):

    return (not q) or p or r

def op4(p,q,r):

    return (not p) or q and r


for i in range(2):
    for j in range(2):
        for k in range(2):
            print(int(ques(i,j,k)),int(op1(i,j,k)),int(op2(i,j,k)),int(op3(i,j,k)),int(op4(i,j,k)))



