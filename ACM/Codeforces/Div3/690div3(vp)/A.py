import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = list (map (int ,input ().split ()))
  for i in range (n // 2 + 1) :
    if i > n - i - 1 : break
    elif i == n - i - 1 : print (a[i], end = " ")
    else : print (a[i], a[n - i - 1], end = " ")
  print ()
  
for t in range (int (input ())) : charming ()
