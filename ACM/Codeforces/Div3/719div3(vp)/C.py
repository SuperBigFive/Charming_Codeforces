import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  if n == 2 : print (-1); return
  ans = [0] * (n * n + 1); id = 1
  for i in range (1, n * n + 1) :
    ans[(id - 1) % (n * n) + 1] = i; id += n - 1
  for i in range (1, n * n + 1) :
    print (ans[i], end = " ")
    if i % n == 0 : print ()
    
  
for t in range (int (input ())) : charming ()
