import math
M = 10 ** 18; eps = 1e-9
n = int (input ()); p = dict (); ok = set ()
for i in range (n) :
  x, y = map (int, input ().split ())
  p[x] = p.get (x, []) + [y]; ok.add ((x, y))
if len (p) == 1 : print (0); exit (0)
p_key = list (p.keys ())
p_key.sort (reverse = True)
siz = len (p_key); Line = dict (); ans = 0
for i in range (1, siz) :
  x1 = p_key[i]
  for y1 in p[x1] :
    for j in range (i) :
      x2 = p_key[j]
      for y2 in p[x2] :
        if y1 > y2 and (x1, y2) in ok and (x2, y1) in ok : ans += 1
        elif y1 == y2 : continue
        dy = y2 - y1; dx = x2 - x1
        k = 1.0 * dy / dx
        k *= M; k = int (k)
        Line[k] = Line.get (k, []) + [(dx, x1, y1)]
ans *= 2
for k in Line.keys () :
  Line[k].sort (key = lambda x : x[0])
  p = 0; q = 0; siz = len (Line[k])
  while p < siz :
    q = p
    while q + 1 < siz and Line[k][q + 1][0] == Line[k][q][0] : q += 1
    for i in range (p, q) :
      for j in range (i + 1, q + 1) :
        dx, x1, y1 = Line[k][i]
        dx, x2, y2 = Line[k][j]
        if x1 == x2 : continue
        elif abs (1.0 * (y2 - y1) / (x2 - x1) * k / M + 1) < eps : ans += 1
    p = q + 1
print (ans // 2)
  
    
