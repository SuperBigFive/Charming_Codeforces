import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  order = input (); s = input ()
  n = len (s); res = 0
  d = dict ()
  for i in range (26) :
    d[order[i]] = i
  for i in range (1, n) :
    res += abs (d[s[i]] - d[s[i - 1]])
  print (res)

for t in range (int (input ())) : charming ()
