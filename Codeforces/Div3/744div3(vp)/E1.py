import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  a = list (map (int, input ().split ()))
  l, r = list (), list ()
  l.append (a[0])
  for i in range (1, n) :
    if a[i] < l[len (l) - 1] :
      l.append (a[i])
    else : r.append (a[i])
  l = list (reversed (l))
  for i in l : print (i, end = " ")
  for i in r : print (i, end = " ");
  print ()

for t in range (int (input ())) : charming ()
