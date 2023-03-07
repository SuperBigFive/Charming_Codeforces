import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  m = n // 2020
  print ("YES" if m >= n % 2020 else "NO")

for t in range (int (input ())) : charming ()
