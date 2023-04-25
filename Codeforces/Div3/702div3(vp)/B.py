import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = list (map (int, input ().split ()))
  c = [0, 0, 0]
  for i in a : c[i % 3] += 1
  ave = sum (c) // 3; res = 0
  for j in range (100) :
    for i in [2, 0, 1] :
      if c[i] > ave :
        diff = c[i] - ave
        c[i] = ave
        c[(i + 1) % 3] += diff
        res += diff
  print (res)

for t in range (int (input ())) : charming ()
