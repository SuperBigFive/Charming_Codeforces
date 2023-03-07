import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  k = int (input ())
  i = 1; cnt = 0
  while cnt < k :
    if i % 3 and i % 10 != 3 :
      cnt += 1
    i += 1
  print (i - 1)

for t in range (int (input ())) : charming ()
