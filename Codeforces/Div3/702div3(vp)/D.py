import sys
import math
N = int (1e4 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = [0] + list (map (int, input ().split ()))
  dep = [0] * (n + 1)
  def dfs (l, r, d) :
    if l > r : return
    if l == r : dep[l] = d; return
    mx = max (a[l : r + 1])
    mx_id = a[l : r + 1].index (mx) + l  
    dep[mx_id] = d
    dfs (l, mx_id - 1, d + 1)
    dfs (mx_id + 1, r, d + 1)
  dfs (1, n, 0)
  for i in range (1, n + 1) : print (dep[i], end = " ");
  print ()
  
for t in range (int (input ())) : charming ()

