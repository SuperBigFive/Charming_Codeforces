import copy
for t in range (int (input ())) :
  n, m, k = map (int, input ().split ())
  extra = n % m
  people = n // m
  if extra == 0 :
    for i in range (k) :
      cnt = 0
      for j in range (m) :
        print (people, end = " ")
        for p in range (people) :
          cnt += 1;
          print (cnt, end = " ")
        print ("")
    continue
  b = ((people + 1) * extra * k) // n
  eb = ((people + 1) * extra * k) % n
  d = dict ()
  cur = dict ()
  for i in range (1, n + 1) :
    d[i] = b
    cur[i] = 0
    if i <= eb : d[i] += 1
  last = 1
  for i in range (k) :
    cnt1 = 0
    cnt2 = extra
    res = list ()
    l1 = list ()
    l2 = list ()
    for j in list (range (last, n + 1)) + list (range (1, last)):
      if cur[j] < d[j] and cnt1 < extra :
        cur[j] += 1
        l1.append (j)
        last = j + 1
      else : l2.append (j)
      if cnt1 < extra and len (l1) >= people + 1 :
        cnt1 += 1
        res.append (copy.deepcopy (l1))
        l1.clear ()
      if len (l2) >= people :
        cnt2 += 1
        res.append (copy.deepcopy (l2))
        l2.clear ()
    for j in range (m) :
      print (len (res[j]), end = " ")
      for p in range (len (res[j])) :
        print (res[j][p], end = " ")
      print ("")
  
