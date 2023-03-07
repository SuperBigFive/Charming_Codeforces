import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, k = map (int, input ().split ()); s = list ()
  for i in range (n) : s.append (input ())
  s = sorted (s[0 : k])
  for i in range (k) : print (s[i])
    
charming ()
