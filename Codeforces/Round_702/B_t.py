# CODED BY SUMIT KUMAR PRAJAPATI

import os
import io
import sys
import math

MD=int(1e9+7)
MX=int(1e5+2)
pi=3.1415926535897932


def intinp():
    return int(input())

def arinput():
    return list(map(int,input().strip().split()))

def io_file():
    sys.stdin=open("input.txt",'r')
    sys.stdout=open("output.txt",'w')




def solve():
    n=intinp()
    a=arinput()
    mod3=[0,0,0]
    for x in a:
        mod3[x%3]+=1

    each=n//3
    ans=0
    for k in range(2):
        # print(mod3)
        for i in range(3):
            if mod3[i]>each:
                ans+=(mod3[i]-each)
                mod3[(i+1)%3]+=mod3[i]-each
                mod3[i]=each
    # print(mod3)
    print(ans)           





if __name__=='__main__':
    # fast_io()
    io_file()
    tc=1
    tc=intinp()
    for t in range(1,tc+1):
        # print(f"Case #{t}: ",end='')
        solve()


