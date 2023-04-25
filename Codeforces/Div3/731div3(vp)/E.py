import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  input ()
  n, k = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  b = list (map (int, input ().split ()))
  pos = [int (1 << 32)] * (n + 5)
  for i in range (k) : pos[a[i]] = min (pos[a[i]], b[i])
  res = [int (1 << 32)] * (n + 5);
  mn = int (1 << 32)
  for i in range (1,  n + 1) :
    if pos[i] < mn :
      mn = pos[i]
    res[i] = min (res[i], mn)
    mn += 1
  mn = int (1 << 32)
  for i in list (reversed (range (1, n + 1))) :
    if pos[i] < mn :
      mn = pos[i]
    res[i] = min (res[i], mn)
    mn += 1
  for i in range (1, n + 1) : print (res[i], end = " ")
  print ()
  
for t in range (int (input ())) : charming ()
