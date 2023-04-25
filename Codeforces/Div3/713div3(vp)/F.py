import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, c = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  b = list (map (int, input ().split ()))
  l = 1; r = c; res = c
  while l <= r :
    mid = (l + r) // 2; days = 0; money = 0; ok = False
    for i in range (n) :
      if mid < days : break
      if money + (mid - days) * a[i] >= c : ok = True; break
      if i >= n - 1 : break
      if b[i] <= money : money -= b[i]; days += 1; continue
      delta = (b[i] - money - 1) // a[i] + 1
      money += a[i] * delta - b[i]
      days += delta + 1
    if ok : r = mid - 1; res = mid
    else : l = mid + 1
  print (res)
  
for t in range (int (input ())) : charming ()
