import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); s = "#" + input ()
  pre = [0] * (n + 5); suf = [0] * (n + 5)
  vis1 = set (); vis2 = set ()
  for i in range (1, n + 1) :
    pre[i] = pre[i - 1]
    if s[i] not in vis1 : pre[i] += 1; vis1.add (s[i])
  for i in range (n, 0, -1) :
    suf[i] = suf[i + 1]
    if s[i] not in vis2 : suf[i] += 1; vis2.add (s[i])
  res = 1
  for i in range (1, n) :
    res = max (res, pre[i] + suf[i + 1])
  print (res)
  
for t in range (int (input ())) : charming ()
