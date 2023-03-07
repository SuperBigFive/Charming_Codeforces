import math
for t in range (int (input ())) :
  n = int (input ())
  a = list (map (int, input ().split ()))
  b1 = a[0 : n : 2]
  b2 = a[1 : n : 2]
  d1 = b1[0]
  d2 = b2[0]
  for i in b1 :
    d1 = math.gcd (d1, i)
  ok = True
  for i in b2 :
    if i % d1 == 0 :
      ok = False
      break
  if ok == True :
    print (d1)
    continue
  for i in b2 :
    d2 = math.gcd (d2, i)
  ok = True
  for i in b1 :
    if i % d2 == 0 :
      ok = False
      break
  print (d2 if ok == True else 0)
