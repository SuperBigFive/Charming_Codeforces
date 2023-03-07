import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); s = input ()
  p = 0; q = n - 1
  while p <= q and (ord (s[p]) - ord ('0')) ^\
        (ord (s[q]) - ord ('0')) :
    p += 1
    q -= 1
  print (max (0, q - p + 1))

for t in range (int (input ())) : charming ()
