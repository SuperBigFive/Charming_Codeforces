import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, k = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  b = list (zip (a, range (n)))
  b.sort (key = lambda x : x[0])
  cnt = 0; color = [0] * n; c = 1
  stk = list ()
  for i in range (n) :
    if i == 0 or b[i - 1][0] != b[i][0] : cnt = 1
    else : cnt += 1
    if cnt > k : continue
    else :
      color[b[i][1]] = (c - 1) % k + 1
      c += 1; stk.append (i)
  c = (c - 1) % k + 1; siz = len (stk)
  for i in range (siz - (c - 1), siz) : color[b[stk[i]][1]] = 0
  for i in color : print (i, end = " ")
  print ()

for t in range (int (input ())) : charming ()
