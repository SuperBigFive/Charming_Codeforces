import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  x = int (input ())
  if x > 45 : print (-1); return
  res = list ()
  for i in range (9, 0, -1) :
    if x >= i :
      res.append (i)
      x -= i
  if x : print (-1); return
  res = list (reversed (res))
  for i in res : print (i, end = "")
  print ()
  
for t in range (int (input ())) : charming ()

