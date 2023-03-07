import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = list (map (int, input ().split ())); cnt = 0
  for i in range (n) :
    if a[i] < 0 : a[i] = -a[i]; cnt += 1
  cnt &= 1
  a.sort (reverse = True); res = 0
  for i in range (n) :
    if i < n - cnt : res += a[i]
    else : res -= a[i]
  print (res)
  
for t in range (int (input ())) : charming ()
