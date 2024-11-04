N = 105

pow10 = [1] * N
for i in range (1, N) : pow10[i] = pow10[i - 1] * 10

for _ in range (int (input ())) :
  x = int (input ())
  y = int (input ())
  if x > y : x, y = y, x
  mid = (x + y) // 2
  dx, dy = [], []
  tmpx, tmpy = x, y
  while tmpx :
    dx.append (tmpx % 10)
    dy.append (tmpy % 10)
    tmpx //= 10
    tmpy //= 10
  n = len (dx)
  lst = x * y
  for i in range (n) :
    nx = x + (dy[i] - dx[i]) * pow10[i]
    ny = y + (dx[i] - dy[i]) * pow10[i]
    prod = nx * ny
    if prod > lst :
      lst = prod
      x = nx
      y = ny
  print (x)
  print (y)