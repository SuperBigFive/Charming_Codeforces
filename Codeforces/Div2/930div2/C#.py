import sys

def ask (a, b, c, d) :
  print ('?', a, b, c, d)
  sys.stdout.flush ()
  return input ()

def answer (i, j) :
  print ('!', i, j)
  sys.stdout.flush ()

def solve1 (a) :
  b = 0 if a else 1
  stk = [b]
  for d in range (n) :
    if d == a : continue
    ret = ask (a, b, a, d)
    if ret == '=' :
      stk.append (d)
    elif ret == '<' :
      b = d
      stk = [d]
  return stk

def solve2 (stk) :
  mn = stk[0]
  for i in range (1, len (stk)) :
    if ask (mn, mn, stk[i], stk[i]) == '>' :
      mn = stk[i]
  return mn

for _ in range (int (input ())) :
  n = int (input ())
  stk1 = solve1 (0)
  stk2 = solve1 (stk1[0])
  mn1, mn2 = solve2 (stk1), solve2 (stk2)
  a1, a2 = 0, stk1[0]
  if ask (a1, mn1, a2, mn2) == '>' : answer (a1, mn1)
  else : answer (a2, mn2)
