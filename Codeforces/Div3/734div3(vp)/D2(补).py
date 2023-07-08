import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, m, k = map (int, input ().split ());
  ok = True; rev = False
  layout1 = list (); layout2 = list ()
  if n & 1 or m & 1 :
    if m & 1 :
      tmp = n; n = m; m = tmp
      rev = True; k = n * m // 2 - k
    else : rev = 0
    layout1 = list (['#'] * (m + 1))
    if k < m // 2 or (k - m // 2) & 1 : ok = False
    for i in range (1, m, 2) :
      if k : layout1[i] = layout1[i + 1] = chr (ord ('a') + 24 + (i // 2) % 2)
      k -= 1
    n -= 1
  layout2 = list (['#'] * (m + 1) for i in range (n + 1))
  if ok == 0  or (k & 1) :
    print ("NO")
    return
  for j in range (1, m, 2) :
    for i in range (1, n + 1) :
      if k == 0 : break
      layout2[i][j] = layout2[i][j + 1] =\
                      chr (ord ('a') + 2 + ((i & 1) * 2 + ((j // 2) & 1)))
      k -= 1
    if k == 0 : break
  for i in range (1, n, 2) :
    for j in range (1, m + 1) :
      if layout2[i][j] != '#' : continue
      layout2[i][j] = layout2[i + 1][j] =\
                      chr (ord ('a') + 6 + ((j & 1) * 2 + ((i // 2) & 1)))
  layout = [['#'] * (m + 1)]
  if len (layout1) : layout += [layout1] + layout2[1 : n + 1]
  else : layout += layout2[1 : n + 1]
  print ("YES")
  '''if rev == True :
    for i in range (1, m + 1) :
      for j in range (1, n + 2) :
        print (layout[j][i], end = "")
      print ()
  else :
    for i in range (1, len (layout)) :
      for j in range (1, m + 1) :
        print (layout[i][j], end = "")
      print ()'''

for t in range (int (input ())) : charming ()
