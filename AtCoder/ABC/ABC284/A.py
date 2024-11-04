import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  s = list ()
  for i in range (n) : s.append (input ())
  s.reverse ()
  for i in s : print (i)

charming ()
