for t in range (int (input ())) :
  n = int (input ())
  b = list (map (int, input ().split ()))
  if n == 1 :
    print ("YES\n%d" % b[0])
    continue
  elif n == 2 :
    if (2 * b[0] - b[1]) % 3 > 0 or 2 * b[0] - b[1] <= 0 :
      print ("NO")
      continue
    if (2 * b[1] - b[0]) % 3 > 0 or 2 * b[1] - b[0] <= 0 :
      print ("NO")
      continue
    print ("YES")
    print ((2 * b[1] - b[0]) // 3, (2 * b[0] - b[1]) // 3)
  else :
    ok = True
    A1 = [1] + list (reversed (range (2, n)))
    for i in list (reversed (range (1, n))) :
      b[i] -= b[i - 1]
    for i in list (range (2, n)) :
      b[i] -= b[1]
      if b[i] % n != 0 :
        ok = False
        break
      b[i] = b[i] // n
    if ok == False :
      print ("NO")
      continue
    k = n
    for i in range (2, n) :
      k += n - (i - 1)
      b[0] += (n - (i - 1)) * b[i]
      b[1] += b[i]
    k += 1
    b[0] -= b[1]
    if b[0] % k != 0 :
      print ("NO")
      continue
    b[0] = b[0] // k
    for i in range (1, n) :
      if i == 1 :
        b[i] += b[0]
      else :
        b[i] -= b[0]
    res = [0] * n
    res[0] = b[1]
    res[1] = b[0]
    for i in range (2, n) :
      res[i] = -b[i]
    for i in range (0, n) :
      if res[i] < 1 or res[i] > 1e9 :
        ok = False
        break
    if ok == False :
      print ("NO")
      continue
    print ("YES")
    for i in res :
      print (i, end = " ")
    print ("")
    
         
