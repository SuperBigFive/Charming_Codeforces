import sys
import math
N = int (1e4 + 5)
sys.setrecursionlimit (N)

def charming () :
  x = int (input ())
  p = 1; q = N
  while p <= q and p * p * p <= x:
    while p * p * p + q * q * q > x : q -= 1
    if q < p : break
    if p * p * p + q * q * q == x : print ("YES"); return
    p += 1
  print ("NO")

for t in range (int (input ())) : charming ()
