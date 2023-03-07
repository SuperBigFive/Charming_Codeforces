import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, l, r = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  pl = n; pr = n - 1; res = 0
  a.sort ()
  for i in range (n) :
    while pl - 1 >= 0 and a[pl - 1] + a[i] >= l : pl -=1
    while pr >= 0 and a[pr] + a[i] > r : pr -= 1
    res += pr - pl + 1 - (2 * a[i] >= l and 2 * a[i] <= r)
  print (res // 2)

for t in range (int (input ())) : charming ()
