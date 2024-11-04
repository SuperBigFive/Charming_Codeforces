import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  for i in range (n) :
    a, b = map (int, input ().split ())
    print (a + b)
    
charming ()
