for _ in range (int (input ())) :
  n, m = map (int, input ().split ())
  mp = [input ().strip () for _ in range (n)]
  if mp[0][0] == mp[n - 1][m - 1] :
    print ('Yes')
  else :
    ok = False
    for _ in range (4) :
      nmp = [[0] * n for i in range (m)]
      for i in range (n) :
        for j in range (m) :
          nmp[j][n - i - 1] = mp[i][j]
      n, m = m, n
      mp = nmp
      col0_b, col0_w = 0, 0
      for i in range (n) :
        if mp[i][0] == 'B' : col0_b = 1
        else : col0_w = 1
      row0_b, row0_w = 0, 0
      for i in range (m) :
        if mp[0][i] == 'B' : row0_b = 1
        else : row0_w = 1
      if col0_b and row0_b and mp[n - 1][m - 1] == 'B' :
        ok = True
      if col0_w and row0_w and mp[n - 1][m - 1] == 'W' :
        ok = True
    if ok : print ('Yes')
    else : print ('No')