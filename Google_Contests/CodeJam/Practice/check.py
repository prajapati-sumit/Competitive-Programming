n=5
def myfunction():
    global n
    n=n+1
    print(n)
    yield n
    n=n+1
    yield n
    n=n+1
    yield n

a=myfunction()
print(" 1",next(myfunction()))
print(" 2",next(myfunction()))
print(" 3",next(myfunction()))