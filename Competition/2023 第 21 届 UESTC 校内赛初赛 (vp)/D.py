for t in range (int (input ())) :
  n = int (input ()); Line = dict ()
  for i in range (n) :
    x1, y1, x2, y2 = map (int, input ().split ())
    bel = x1 + y1
    Line[bel] = Line.get (bel, []) + [[x1, x2]]
  ok = True; ans = 0
  for i in Line.keys () :
    Line[i].sort (key = lambda x : x[0])
    siz = len (Line[i]); p = 0
    while p < siz :
      q = p; mx = Line[i][p][1]
      while q + 1 < siz and Line[i][q + 1][0] <= mx :
        if Line[i][q + 1][0] < Line[i][q][1] : ok = False
        q = q + 1
        mx = max (mx, Line[i][q][1])
      ans += mx - Line[i][p][0]
      p = q + 1
  print ("YES" if ok else "NO")
  print (ans)
