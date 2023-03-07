import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

n = int ()
b = list ()

def get () :
  global n, b
  last = 1
  b = [[1]]
  for i in range (1, 64) :
    last *= 2
    cnt = 0; tmp = last
    c = list ()
    while tmp :
      c.append (tmp % 10)
      tmp //= 10
    b.append (c)

def charming () :
  global n, b
  n = int (input ())
  a = list ()
  while n :
    a.append (n % 10)
    n //= 10
  res = 25
  for pow2 in b :
    p = len (pow2) - 1; ans = 0
    for i in list (reversed (range (len (a)))) :
      if pow2[p] == a[i] and p >= 0 : p -= 1
      else : ans += 1
      
    res = min (res, ans + p + 1)
  print (res)

get ()
for t in range (int (input ())) : charming ()
