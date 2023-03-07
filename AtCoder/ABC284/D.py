import sys
import math
N = int (3e6 + 5)
sys.setrecursionlimit (N)

def sieve () :
  for i in range (2, N) :
    if vis[i] == 0 : prim.append (i)
    for j in prim :
      if j * i >= N : break
      vis[i * j] = 1
      if i % j == 0 : break

def charming () :
  n = int (input ())
  p, q = int (), int ()
  for i in prim :
    if n % i == 0 :
      if n % (i * i) == 0 :
        print (i, n // (i * i))
      else :
        print (int (math.sqrt (n // i)), i)
      return

prim = list (); vis = [0] * (N)
sieve ()
for t in range (int (input ())) : charming ()
