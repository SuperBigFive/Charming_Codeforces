import random
M = 10 ** 10

for t in range (int (input ())) :
  n = int (input ())
  d = dict (); pre = dict (); siz = dict (); edge = []
  bel = [[0, 0, 0] for i in range (n + 5)]

  for i in range (n) :
    a, b, c = map (int, input ().split ())
    if a > b : a, b = b, a
    if b > c : b, c = c, b
    if a > b : a, b = b, a
    hash_ab = a * M + b
    hash_bc = b * M + c
    hash_ac = a * M + c
    bel[i] = [hash_ab, hash_bc, hash_ac]
    if hash_ab not in d : d[hash_ab] = set (); d[hash_ab].add (i)
    else : d[hash_ab].add (i)
    if hash_bc not in d : d[hash_bc] = set (); d[hash_bc].add (i)
    else : d[hash_bc].add (i)
    if hash_ac not in d : d[hash_ac] = set (); d[hash_ac].add (i)
    else : d[hash_ac].add (i)
    siz[hash_ab] = siz.get (hash_ab, 0) + 1
    siz[hash_bc] = siz.get (hash_bc, 0) + 1
    siz[hash_ac] = siz.get (hash_ac, 0) + 1
    pre[hash_ab] = hash_ab
    pre[hash_bc] = hash_bc
    pre[hash_ac] = hash_ac
    edge.append ((hash_ab, hash_bc))
    edge.append ((hash_bc, hash_ac))
    edge.append ((hash_ab, hash_ac))

  def find (x) :
    if x == pre[x] : return x
    pre[x] = find (pre[x])
    return pre[x]

  key = list (pre.keys ())
  siz = len (key)
  
  for u, v in edge :
    r = random.randint (0, siz - 1)
    find (key[r])
    fu = find (u); fv = find (v)
    if fu == fv : continue
    else : pre[fu] = fv
  ans = []
  for i in range (n) :
    f = [find (bel[i][0]), find (bel[i][1]), find (bel[i][2])]
    for j in f : d[j].add (i)
  for i in pre.keys () :
    if i == pre[i] : ans.append (len (d[i]))
  ans.sort ()
  print (len (ans))
  for i in ans : print (i, end = " ")
  print ()
    
