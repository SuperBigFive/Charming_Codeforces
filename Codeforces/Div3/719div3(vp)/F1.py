import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def ask (l, r) -> int :
  print ("?", l, r)
  sys.stdout.flush ()
  return int (input ())

def ans (k) : print ("!", k)

def charming () :
  n, t = map (int, input ().split ())
  k = int (input ())
  l = 1; r = n;
  while l < r :
    mid = (l + r) // 2
    val_l = mid - l + 1 - ask (l, mid)
    if val_l < k : k -= val_l; l = mid + 1
    else : r = mid
  ans (l)
  
charming ()
