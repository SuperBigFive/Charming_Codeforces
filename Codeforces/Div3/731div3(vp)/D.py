import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  x = list (map (int, input ().split ()))
  Xor = 0;
  for i in range (len (x)) :
    if i == 0 : print (0, end = " ")
    else : print (Xor ^ (Xor & x[i]), end = " ")
    Xor = x[i] | (x[i] ^ Xor)
  print ()
  
for t in range (int (input ())) : charming ()
