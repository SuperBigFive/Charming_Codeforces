import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  x, y, a, b = map (int, input ().split ())
  if a > b : tmp = a; a = b; b = tmp
  l1 = 0; r1 = int (1e9); res = r1
  while l1 <= r1 :
    mid1 = (l1 + r1) // 2
    l2 = 0; r2 = mid1; k = mid1
    if a * mid1 > x : r1 = mid1 - 1; continue
    while l2 <= r2 :
      mid2 = (l2 + r2) // 2
      if a * mid2 + b * (mid1 - mid2) > x : l2 = mid2 + 1
      else : r2 = mid2 - 1; k = mid2
    if a * (mid1 - k) + b * k <= y and a * k + b * (mid1 - k) <= x:
      l1 = mid1 + 1; res = mid1
    else : r1 = mid1 - 1
  print (res)

for t in range (int (input ())) : charming ()
