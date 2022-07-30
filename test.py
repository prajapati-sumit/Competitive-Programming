# def appendzero(s):
  return s + '0' * len(s)

def expand(s):
  return s + s

def P(k):
  if k == 0:
      return ['1']
  seq = P(k - 1)
  seq_with_zero = [appendzero(s) for s in seq]
  seq_with_copy = [expand(s) for s in seq]
  res = seq_with_copy[:]
  for ins in seq_with_zero:
      res += [ins]
      res += seq_with_copy
  return res

hidden="10000110"

def fn(v):
    print(v)
    global hidden
    res = ['0' if v[i]==hidden[i] else '1' for i in range(8)]
    hidden = ''.join(res)
    x = 0
    for i in range(8):
        x += hidden[i]=='1'
    # print(hidden,x)
    x = int(input())
    return x

p = P(3)

t = int(input())
for tt in range(t):
    ok = False
    for b in p:
        if fn(b)==0:
            ok = True
            break
    assert(ok)


