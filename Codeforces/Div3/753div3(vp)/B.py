import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

x0, n = int (), int ()

def charming () :
  global x0, n
  x0, n = map (int, input ().split ())
  sign = list ()
  if x0 & 1 == 1 : sign = [1, -1, -1, 1]
  else : sign = [-1, 1, 1, -1]
  move = range (4 * (n // 4) + 1, n + 1)
  res = x0
  for i in range (len (move)) :
    res += move[i] * sign[i]
  print (res)

for t in range (int (input ())) : charming ()
