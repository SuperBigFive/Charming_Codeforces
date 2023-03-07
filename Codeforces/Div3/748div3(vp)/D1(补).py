import sys
import math
N = int (1e6 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  a = list (map (int, input ().split ()))
  a.sort ()
  b = list (); b.append (a[0])
  for i in range (1, n) :
    if a[i] !=  a[i - 1] : b.append (a[i])
  if len (b) <= 1 :
    print (-1)
    return
  GCD = b[1] - b[0]
  for i in range (2, len (b)) : GCD = math.gcd (GCD, b[i] - b[i - 1])
  print (GCD)

for t in range (int (input ())) : charming ()
