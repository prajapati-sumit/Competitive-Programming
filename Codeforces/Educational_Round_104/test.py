import os
import sys
import math
MD=int(1e9+7)
pi=3.1415926535897932


def intinp():
    return int(input())

def arinput():
    return list(map(int,input().strip().split()))


def solve():
    a=arinput()
    print(a)
    print(MD)
    print(pi)



def iofile():
    sys.stdin=open("input.txt",'r')
    sys.stdout=open("output.txt",'w')



if __name__=='__main__':

    iofile()
    tc=1
    tc=intinp()
    for t in range(1,tc+1):
        # print(f"Case #{t}: ",end='')
        solve()


