import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

for t in range (int (input ())) :
  n, k = map (int, input ().split ())
  ok1 = False; ok2 = False
  for i in range (n) :
    seq = list (map (int, input ().split ()))
    if seq[0] == k : ok1 = True
    if seq[1] == k : ok2 = True
  print ("YES" if ok1 and ok2 else "NO")
