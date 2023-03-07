import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  a, b, c = map (int, input ().split ())
  n = abs (a - b) * 2
  if max ([a, b, c]) > n :
    print (-1)
    return
  ans = (c + n // 2) % n
  if ans == 0 : ans = n
  print (ans)

for t in range (int (input ())) : charming ()
