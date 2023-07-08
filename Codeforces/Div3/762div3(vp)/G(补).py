for t in range (int (input ())) :
  s = input ()
  n, k = map (int, input ().split ())
  mine = list ()
  dx = dict ()
  dy = dict ()
  x_pos = list ()
  y_pos = list ()
  cntx = 0
  cnty = 0
  for i in range (n) :
    data = tuple (map (int, input ().split ()))
    mine.append (data)
    if not(data[0] in dx) :
      dx[data[0]] = cntx
      y_pos.append (list ())
      cntx += 1
    y_pos[dx[data[0]]].append ((data[1], i))
    if not(data[1] in dy) :
      dy[data[1]] = cnty
      x_pos.append (list ())
      cnty += 1
    x_pos[dy[data[1]]].append ((data[0], i))
  for i in range (cntx) :
    y_pos[i] = sorted (y_pos[i])
  for i in range (cnty) :
    x_pos[i] = sorted (x_pos[i])
  pre = [0] * n
  mn = [2e9] * n
  for i in range (n) :
    pre[i] = i
    mn[i] = mine[i][2]
  def find (x) :
    if x == pre[x] :
      return x
    pre[x] = find (pre[x])
    return pre[x]
  edge = list ()
  def find_right (my_list, value) :
    l = 0
    r = len (my_list)
    res = 0
    while l <= r :
      mid = (l + r) // 2
      if mid == len (my_list) :
        res = mid
        break
      elif my_list[mid][0] <= value :
        l = mid + 1
      else :
        r = mid - 1
        res = mid
    return res
  def find_left (my_list, value) :
    l = -1
    r = len (my_list) - 1
    res = 0
    while l <= r :
      mid = (l + r) // 2
      if mid == -1 :
        res = mid
        break
      elif my_list[mid][0] < value :
        l = mid + 1
        res = mid
      else :
         r = mid - 1
    return res
  for i in range (n) :
    x = mine[i][0]
    y = mine[i][1]
    idy_pos = find_right (y_pos[dx[x]], y)
    idy_neg = find_left (y_pos[dx[x]], y)
    if idy_pos < len (y_pos[dx[x]]) and \
    y_pos[dx[x]][idy_pos][0] - y <= k :
      edge.append ((i, y_pos[dx[x]][idy_pos][1]))
    if idy_neg > -1 and \
    y - y_pos[dx[x]][idy_neg][0] <= k :
      edge.append ((i, y_pos[dx[x]][idy_neg][1]))
    idx_pos = find_right (x_pos[dy[y]], x)
    idx_neg = find_left (x_pos[dy[y]], x)
    if idx_pos < len (x_pos[dy[y]]) and \
    x_pos[dy[y]][idx_pos][0] - x <= k :
      edge.append ((i, x_pos[dy[y]][idx_pos][1]))
    if idx_neg > -1 and \
    x - x_pos[dy[y]][idx_neg][0] <= k :
      edge.append ((i, x_pos[dy[y]][idx_neg][1]))
  for u, v in edge :
    fu = find (u)
    fv = find (v)
    if fu == fv :
      continue
    pre[fu] = fv
    mn[fv] = min (mn[fv], mn[fu])
  res = list ()
  for i in range (n) :
    if i != pre[i] :
      continue
    res.append (mn[i])
  res = sorted (res, reverse = True)
  times = 0
  while (times + 1 < len (res) and times + 1 <= res[times + 1]) :
    times += 1
  print (times)
      
