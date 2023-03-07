import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

n , m = int (), int ()
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def charming () :
  global n, m
  n, m = map (int, input ().split ())
  opt = input ()
  d = {"U": 0, "R" : 1, "D" : 2, "L" : 3}
  res1, res2 = 1, 1
  cntx, cnty = 0, 0
  mnx, mxx = 0, 0
  mny, mxy = 0, 0
  flag1, flag2 = True, True
  for i in opt :
    id = d[i]
    cntx += dx[id]; cnty += dy[id]
    mnx = min (mnx, cntx)
    mxx = max (mxx, cntx)
    mny = min (mny, cnty)
    mxy = max (mxy, cnty)
    lx = 1 - mnx
    rx = n - mxx
    ly = 1 - mny
    ry = m - mxy
    if id == 0 or id == 2 :
      if lx <= rx : res1 = lx
      else : break
    if (id == 1 or id == 3) :
      if ly <= ry : res2 = ly
      else : break
  print (res1, res2)
  
for t in range (int (input ())) : charming ()
