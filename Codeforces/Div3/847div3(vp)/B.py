import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, s, r = map (int, input ().split ())
  print (s - r, end = " ")
  mx = s - r
  for i in range (n - 1) :
    for j in range (mx, 0, -1) :
      #print (s - j, end = " ")
      if r - j + 1>= n - 1 - i:
        print (j, end = " ")
        r -= j
        break
  print ()
  
for t in range (int (input ())) : charming ()
