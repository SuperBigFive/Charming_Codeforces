import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = [0] + list (map (int, input ().split ()))
  d = dict (); res = 0
  for i in range (1, n + 1) :
    a[i] = a[i] - i;
    if a[i] in d : d[a[i]] += 1
    else : d[a[i]] = 1
  for i in range (1, n + 1) :
    d[a[i]] -= 1; res += d[a[i]]
  print (res)
  
for t in range (int (input ())) : charming ()
