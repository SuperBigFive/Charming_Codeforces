import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  input ()
  k, n, m = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  b = list (map (int, input ().split ()))
  res = list (); p = 0
  for i in a :
    if i == 0: k += 1
    elif i > k :
      while p < len (b) :
        if b[p] == 0 : p += 1; k += 1; res.append (b[p - 1])
        elif b[p] <= k : p += 1; res.append (b[p - 1])
        else : break
      if i > k : print ("-1"); return
    res.append (i)
  for i in b[p : len (b)] :
    if i == 0 : k += 1
    elif i > k : print ("-1"); return
    res.append (i)
  for i in res : print (i, end = " ")
  print ()
  
for t in range (int (input ())) : charming ()
