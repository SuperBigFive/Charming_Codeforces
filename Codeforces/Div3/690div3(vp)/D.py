import sys
import copy
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = list (map (int, input ().split ()))
  res = n - 1
  for remain in range (1, n + 1) :
    if sum (a) % remain : continue
    ave = sum (a) // remain; p = 0; na = copy.deepcopy (a)
    ok = True; opt = 0
    while p < n :
      q = p + 1
      while q < n and na[p] < ave :
        na[p] += na[q]
        q += 1
      opt += q - p - 1
      if na[p] > ave : ok = False; break
      p = q
    if ok : res = min (res, opt)
  print (res)
  
for t in range (int (input ())) : charming ()

