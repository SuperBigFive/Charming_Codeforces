import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  a = list (map (int, input ().split ()))
  cnt = 0
  for i in a :
    if i & 1 : cnt += 1
  print (cnt)

for t in range (int (input ())) : charming ()
