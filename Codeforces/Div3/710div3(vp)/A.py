import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, m, x = map (int, input ().split ())
  c = (x - 1) // n + 1; r = (x - 1) % n + 1
  print ((r - 1) * m + c)

for t in range (int (input ())) : charming ()
