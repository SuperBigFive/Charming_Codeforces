import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  a = list (map (int, input ().split ()))
  a = list (zip (a, range (1, n + 1)))
  a.sort (key = lambda x : x[0], reverse = True)
  res = list (); id = 0
  for i in range (1, n) :
    while a[i][0] > 0 and a[id][0] > 0 :
      res += [[a[i][1], a[id][1]]];
      a[id] = (a[id][0] - 1, a[id][1])
      a[i] = (a[i][0] - 1, a[i][1])
    if a[id][0] <= 0 : id = i
  if a[id][0] > 0 :
    siz = len (res)
    for i in range (siz) :
      if a[id][0] <= 0 : break
      if res[i][0] != a[id][1] and res[i][1] != a[id][1] :
        a[id] = (a[id][0] - 1, a[id][1])
        tmp = res[i][0]
        res[i][0] = a[id][1]
        if a[id][0] > 0 :
          res.append ([tmp, a[id][1]])
          a[id] = (a[id][0] - 1, a[id][1])
  print (len (res))
  for i, j in res :
    print (i, j)
  
for t in range (int (input ())) : charming ()
