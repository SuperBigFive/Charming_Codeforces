import sys
N = int (2e5 + 5)
#sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); s = '#' + input ()
  if n == 1 : print (0); return
  id = 1; pre = [0] * (n + 1); pos = [0]
  for i in range (1, n + 1) :
    if s[i] == '*' : pre[i] += 1; pos.append (i)
  l = 1; r = n - len (pos) + 2; res = n * n
  while l <= r :
    mid1 = l + (r - l) // 3
    mid2 = r - (r - l) // 3 
    res1 = 0; res2 = 0
    for i in range (1, len (pos)) :
      res1 += abs (mid1 + i - 1 - pos[i])
      res2 += abs (mid2 + i - 1 - pos[i])
    if res1 <= res2 : r = mid2 - 1
    else : l = mid1 + 1
    res = min (res, res1, res2)
  print (res)
for t in range (int (input ())) : charming ()
