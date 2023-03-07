import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  res = 0
  for i in range (1, 10) :
    num = 0
    for j in range (11) :
      num = num * 10 + i
      if num <= n : res += 1
  print (res)
  
for t in range (int (input ())) : charming ()
