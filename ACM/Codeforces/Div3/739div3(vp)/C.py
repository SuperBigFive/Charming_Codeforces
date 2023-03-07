import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  k = int (input ())
  remain = 1; add = 1; c = 1
  while remain + add <= k :
    remain += add
    add += 2; c += 1
  if remain + c - 1 >= k :
    print (k - remain + 1, c)
  else :
    remain += c - 1
    print (c, c - (k - remain))

for t in range (int (input ())) : charming ()
