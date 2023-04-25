import sys
import math
N = int (1e4 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = [0] + list (map (int, input ().split ()))
  d1 = dict (); d2 = dict ()
  for i in range (1, n + 1) :
    if a[i] not in d1 : d1[a[i]] = 1
    else : d1[a[i]] += 1
  for i in d1.keys () :
    if d1[i] not in d2 : d2[d1[i]] = 1
    else : d2[d1[i]] += 1
  Sum = 0; cnt = 0
  for i in d2.keys () :
    Sum += i * d2[i]
    cnt += d2[i]
  res = Sum; mx = 0
  keys = list (d2.keys ())
  keys.sort ()
  for i in keys :
    mx = max (mx, i * cnt)
    cnt -= d2[i]
  print (res - mx)
  
for t in range (int (input ())) : charming ()

