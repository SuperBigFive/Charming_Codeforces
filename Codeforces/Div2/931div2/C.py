import sys

def ask (x, y) :
  print ('?', x, y)
  sys.stdout.flush ()
  return int (input ())

def answer (x, y) :
  print ('!', x, y)
  sys.stdout.flush ()

def transform (n, m, x, y) :
  return (n - y, x + 1)

def Check (line0, line1) :
  k0, b0 = line0
  k1, b1 = line1
  if abs (b0 - b1) & 1 : return None
  else :
    x = (b1 - b0) // (k0 - k1)
    y = k0 * x + b0
    if x >= 0 and x < m and y >= 0 and y < n :
      return [x, y]
    else :
      return None

for _ in range (int (input ())) :
  n, m = map (int, input ().split ())
  line = []
  dis1 = ask (1, 1)
  line.append ((1, n - dis1 - 1))
  dis2 = ask (n, m)
  line.append ((1, dis2 - (m - 1)))
  dis = ask (n, 1)
  line.append ((-1, dis))
  p0 = Check (line[0], line[2])
  p1 = Check (line[1], line[2])
  # print (p0, p1)
  if p0 and p1 :
    p0[0], p0[1] = transform (n, m, p0[0], p0[1])
    if ask (p0[0], p0[1]) == 0 :
      answer (p0[0], p0[1])
    else :
      mine = transform (n, m, p1[0], p1[1])
      answer (mine[0], mine[1])
  elif p0 :
    mine = transform (n, m, p0[0], p0[1])
    answer (mine[0], mine[1])
  else :
    mine = transform (n, m, p1[0], p1[1])
    answer (mine[0], mine[1])