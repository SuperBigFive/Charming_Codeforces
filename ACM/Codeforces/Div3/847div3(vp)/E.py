import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  x = int (input ())
  if (x & 1) == 1 : print (-1); return
  two = list ()
  for i in range (32) :
    if (x // pow (2, i)) & 1 : two.append (i)
  a = x + pow (2, two[0] - 1); b = pow (2, two[0] - 1)
  for i in range (1, len (two)) :
    if two[i] == two[i - 1] + 1 : print (-1); return
    a += pow (2, two[i] - 1); b += pow (2, two[i] - 1)
  if a ^ b == (a + b) // 2 : print (a, b)
  else : print (-1)
  
for t in range (int (input ())) : charming ()
