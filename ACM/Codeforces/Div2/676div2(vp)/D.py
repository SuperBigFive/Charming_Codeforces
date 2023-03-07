for t in range (int (input ())) :
  x, y = map (int, input ().split ())
  c = list (map (int, input ().split ()))
  dy = [1, 1, 0, -1, -1, 0]; dx = [1, 0, -1, -1, 0, 1]
  res = 100000000000000000000
  for i in range (6) :
    for j in range (6) :
      if i == j : continue
      x1 = dx[i]; y1 = dy[i]
      x2 = dx[j]; y2 = dy[j]
      if x1 * y2 == x2 * y1 : continue
      a = (x * y2 - x2 * y) // (x1 * y2 - x2 * y1)
      b = (x * y1 - x1 * y) // (x2 * y1 - x1 * y2)
      if a < 0 or b < 0 : continue
      res = min (res, a * c[i] + b * c[j])
  print (res)
