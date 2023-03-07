import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = list (map (int, input ().split ()))
  d = dict ()
  for i in range (n) :
    if a[i] not in d : d[a[i]] = (1, i + 1)
    else : d[a[i]] = (-1, i + 1)
  for i in d.keys () :
    if d[i][0] == 1 : print (d[i][1]); return

for t in range (int (input ())) : charming ()
