import sys
import math
N = int (1e4 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = [0] + list (map (int, input ().split ()))
  a = list (zip (a, range (n + 1)))
  a.sort (key = lambda x : x[0])
  l = 1; r = n; res = n
  while l <= r :
    mid = (l + r) // 2
    Sum = 0; ok = True
    for i in range (1, mid + 1) : Sum += a[i][0]
    for i in range (mid + 1, n + 1) :
      if Sum >= a[i][0] : Sum += a[i][0]
      else : ok = False; break
    if ok : r = mid - 1; res = mid
    else : l = mid + 1
  ans = list ()
  for i in range (res, n + 1) : ans.append (a[i][1])
  ans.sort ()
  print (len (ans))
  for i in ans : print (i, end = " ")
  print ()
  
for t in range (int (input ())) : charming ()
 
