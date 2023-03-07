import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  mp = list ('#');
  p = list (); d = dict ()
  for i in range (1, n + 1) :
    mp.append ('#' + input ())
    for j in range (1, n + 1) :
      if mp[i][j] == '*' : p.append ((i, j))
  if p[0][0] != p[1][0] and p[0][1] != p[1][1] :
    x1, y1 = p[0]; x2, y2 = p[1]
    d[(x1, y2)] = d[(x2, y1)] = 1
  elif p[0][0] == p[1][0] :
    x = p[0][0] % n + 1; y1 = p[0][1]; y2 = p[1][1]
    d[(x, y1)] = d[(x, y2)] = 1
  else :
    x1 = p[0][0]; x2 = p[1][0]; y = p[0][1] % n + 1
    d[(x1, y)] = d[(x2, y)] = 1
  for i in range (1, n + 1) :
    for j in range (1, n + 1) :
      print ('*' if (i, j) in d else mp[i][j], end = '')
    print ()
    
for t in range (int (input ())) : charming ()
