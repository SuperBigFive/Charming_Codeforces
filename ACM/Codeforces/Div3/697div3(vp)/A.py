import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  while not (n & 1) : n //= 2
  if n == 1 : print ("NO")
  else : print ("YES")

for t in range (int (input ())) : charming ()
