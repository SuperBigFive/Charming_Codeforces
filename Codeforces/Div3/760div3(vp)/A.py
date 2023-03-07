for t in range (int (input ())) :
  b = list (map (int, input ().split ()))
  for i in range (2, len (b)) :
    dict1 = dict ()
    for j in range (2, len (b)) :
      if j == i : continue
      if b[j] in dict1 : dict1[b[j]] = dict1[b[j]] + 1
      else : dict1[b[j]] = 1
    num = [b[0] + b[1], b[0] + b[i], b[1] + b[i], b[0] + b[1] + b[i]]
    ok = True
    for sum in num :
      if sum in dict1 :
        dict1[sum] -= 1
        if dict1[sum] <= 0 :
          del dict1[sum]
      else :
        ok = False
        break
    if ok == False or len (dict1.keys ()) > 0 : continue
    print (b[0], " ", b[1], " ", b[i])
    break
