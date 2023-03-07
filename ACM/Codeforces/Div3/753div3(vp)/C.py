import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

n = int ()

def charming () :
  global n
  n = int (input ())
  a = list (map (int, input ().split ()))
  a.sort ()
  res = a[0]
  for i in range (1, n) : res = max (res, a[i] - a[i - 1])
  print (res)

for t in range (int (input ())) : charming ()
