import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  a = list (map (int, input ().split ()))
  
  def shift (l, r, d) :
    a[l : r] = a[l + d : r] + a[l : l + d]

  res = list ()
  for i in range (n - 1) :
    mn = int (1e9 + 5)
    id = 0
    for j in range (i, n) :
      if a[j] < mn :
        mn = a[j]
        id = j
    if id > i : res.append ((i + 1, id + 1, id - i))
    shift (i, id + 1, id - i)
  print (len (res))
  for i, j, k in res : print (i, j, k)
  
for t in range (int (input ())) : charming ()
