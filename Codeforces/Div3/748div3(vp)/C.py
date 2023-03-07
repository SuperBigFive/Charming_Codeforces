import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, k = map (int, input ().split ())
  x = list (map (int, input ().split ()))
  x.sort (reverse = True)
  res = 0; move = 0
  while res < k and x[res] > move : move += n - x[res]; res += 1
  print (res)
  
for t in range (int (input ())) : charming ()
