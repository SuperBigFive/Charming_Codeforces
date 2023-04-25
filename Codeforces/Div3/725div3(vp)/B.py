import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = list (map (int, input ().split ()))
  s = sum (a);
  if s % n : print (-1); return
  a.sort (reverse = True)
  for i in range (n) :
    if a[i] <= s // n :
      print (i)
      return
    

for t in range (int (input ())) : charming ()
