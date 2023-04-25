import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

n = int ()

def charming () :
  a = list (map (int, input ().split ()))
  mx = max (a)
  cnt = 0
  for i in a :
    if i == mx : cnt += 1
  flag = 1 if cnt > 1 else 0
  for i in a :
    if i == mx : print (flag, end = " ")
    else : print (mx - i + 1, end = " ")
  print ("")
  
for t in range (int (input ())) : charming ()
