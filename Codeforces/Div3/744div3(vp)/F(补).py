import sys
N = int (1e6 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, d = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  vis = [0] * n
  res = 0
  for i in range (n) :
    if vis[i] : continue
    j = i;
    b = list ()
    ok = False
    while vis[j] == 0 :
      if a[j] == 0 : ok = True
      b.append (a[j])
      vis[j] = True
      j = (j + d) % n
    if ok == False :
      print (-1)
      return
    p = len (b) - 1
    while p >= 0 and b[p] == 1 : p -= 1
    cnt = len (b) - p - 1
    for i in b :
      if i == 1 :
        cnt += 1
        res = max (res, cnt)
      else : cnt = 0
  print (res)
      

for t in range (int (input ())) : charming ()
