from math import sqrt

def is_pefect(x):
    if x<0:
        return False
    s=int(sqrt(x))
    return s*s==x

for z in range(1000):
    
    x2=z*z-200
    y2=z*z-101

    if is_pefect(x2) and is_pefect(y2):
        print(x2,y2,z)

