def merge_list(a,b):
    i1=0
    i2=0
    n1=len(a)
    n2=len(b)
    c=[]
    while i1<n1 and i2<n2:
        if a[i1]>b[i2]:
            c.append(a[i1])
            i1+=1
        else:
            c.append(b[i2])
            i2+=1
    while i1<n1:
        c.append(a[i1])
        i1+=1
    while i2<n2:
        c.append(b[i2])
        i2+=1
    return c



# largest=-1
# slargest=-1

# for x in a:
#     if x>largest:
#         slargest=largest
#         largest=x
#     elif x>slargest:
#         slargest=x

class Date(object):

    def __init__(self,dd,mm,yy):
        self.dd=dd
        self.mm=mm
        self.yy=yy
    def is_before(self,other):
        if self.yy<other.yy:
            return -1
        if self.yy>other.yy:
            return 1
        if self.mm<other.mm:
            return -1
        if self.mm>other.mm:
            return 1    
        if self.dd<other.dd:
            return -1
        if self.dd>other.dd:
            return 1
        return 0

d1=Date(15,4,2021)
d2=Date(15,4,2021)



def remove_at(a,ind):
    return a[:ind]+a[ind+1:]
    
a=[5, 5, 7, 2, 4, 9, 7, 12, 5, 4, 1]
a=remove_at(a,2)
print(a)



