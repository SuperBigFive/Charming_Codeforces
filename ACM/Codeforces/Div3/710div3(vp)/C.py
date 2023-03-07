import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  a = input (); b = input ()
  n = len (a); m = len (b)
  res = n + m
  a = '#' + a; b = '#' + b;
  for i in range (1, n + 1) :
    for j in range (i, n + 1) :
      for p in range (1, m + 1) :
        for q in range (p, m + 1) :
          if a[i : j + 1] == b[p : q + 1] :
            res = min (res, i - 1 + n - j + p - 1 + m - q)
  print (res)
  
for t in range (int (input ())) : charming ()
