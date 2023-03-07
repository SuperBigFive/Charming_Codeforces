import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  if n % 3 == 0 :
    print (n // 3, n // 3)
  elif n % 3 == 1 :
    print (n // 3 + 1, (n - (n // 3 + 1)) // 2)
  else :
    print (n // 3, (n - (n // 3)) // 2)
    
for t in range (int (input ())) : charming ()
