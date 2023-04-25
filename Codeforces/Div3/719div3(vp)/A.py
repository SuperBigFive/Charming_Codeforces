import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); s = input (); vis = set ()
  vis.add (s[0])
  for i in range (1, n) :
    if s[i] == s[i - 1] : continue
    elif s[i] in vis : print ("NO"); return
    else : vis.add (s[i])
  print ("YES")

for t in range (int (input ())) : charming ()
