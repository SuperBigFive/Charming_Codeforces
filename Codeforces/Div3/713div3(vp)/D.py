import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  b = list (map (int, input ().split ()))
  b.sort (); Sum = sum (b) - b[n + 1]
  for i in range (n + 1) :
    if b[n + 1] == Sum - b[i] :
      for j in range (n + 1) :
        if j != i : print (b[j], end = ' ')
      print ()
      return
  if b[n] == Sum - b[n] :
    for i in range (n) : print (b[i], end = ' ')
    print ();
  else : print (-1)
    
for t in range (int (input ())) : charming ()
