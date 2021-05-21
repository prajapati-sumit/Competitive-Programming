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

def fast_io(): 
    input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def io_file():
    sys.stdin=open("input.txt",'r')
    sys.stdout=open("output.txt",'w')


def binary(a,key):
    l=0
    r=len(a)-1
    ans=r
    while l<=r:
        mid=(l+r)>>1
        if a[mid]>=key:
            ans=mid
            r=mid-1

        else:
            l=mid+1

    return ans


def solve():
    n,m=arinput()
    a=arinput()
    x=arinput()
    s={}
    
    '''
    0 1
    0 1


    '''
    pref=[a[0]]
    for i in range(1,n):
        pref.append(pref[-1]+a[i])

    for i in range(n):
        if pref[i]!=0:
            s[pref[i]]=i
    total=pref[-1]
    # print(pref)
    ans=0
    for xi in x:
        ans=0
        if xi>total:
            if total<=0:
                print(-1,end=" ")
                continue
            ans+=n*(xi//total)
            ans-=1
            xi%=total

            if xi in s:
                ans+=(s[xi]+1)
        else:
            if xi in s:
                ans+=(s[xi])
        print(ans,end=" ")
    print()





if __name__=='__main__':
    fast_io()
    io_file()
    tc=1
    tc=intinp()
    for t in range(1,tc+1):
        # print(f"Case #{t}: ",end='')
        solve()


