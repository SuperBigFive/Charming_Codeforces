import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  p = list ([0, 0] for i in range (3))
  input ()
  for i in range (3) : p[i] = list (map (int, input ().split ()))
  ans = abs (p[1][0] - p[0][0]) + abs (p[1][1] - p[0][1])
  if p[0][0] == p[1][0] and p[0][0] == p[2][0] and p[2][1] \
     < max (p[1][1], p[0][1]) and p[2][1] > min (p[1][1], p[0][1]): ans += 2
  if p[0][1] == p[1][1] and p[0][1] == p[2][1] and p[2][0] \
     < max (p[1][0], p[0][0]) and p[2][0] > min (p[1][0], p[0][0]): ans += 2
  print (ans)
  
for t in range (int (input ())) : charming ()
