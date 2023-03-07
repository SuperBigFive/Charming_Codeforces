import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = list (map (int, input ().split ()))
  d = dict (); mx = 0
  for i in a :
    if i not in d : d[i] = 1
    else : d[i] += 1
    mx = max (mx, d[i])
  if mx <= n - mx : print (n & 1); return
  else : print (mx - n + mx)
  
for t in range (int (input ())) : charming ()
