import math
def sieve(n):
    isprime=[1]*n
    isprime[0]=isprime[1]=0


    for i in range(1,n):
        if i*i>n:
            break
        if isprime[i]:
            for j in range(i*i,n,i):
                isprime[j]=0

    primes=[]
    for i in range(n):
        if isprime[i]:
            primes.append(i)

    print(primes)

sieve(33)
