import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = list (map (int, input ().split ()))
  mn = n + 1; mx = 0; id1 = 0; id2 = 0
  for i in range (n):
    if mn > a[i] : mn = a[i]; id1 = i
    if mx < a[i] : mx = a[i]; id2 = i
  if id1 > id2 : tmp = id1; id1 = id2; id2 = tmp
  print (min (id1 + 1 + n - id2, id2 + 1, n - id1))

for t in range (int (input ())) : charming ()
