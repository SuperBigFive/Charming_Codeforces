for t in range (int (input ())) :
  d = dict ();
  n = int (input ())
  res = 0
  for i in range (1, n + 1) :
    num1 = i ** 2
    num2 = i ** 3
    if num1 > n : break
    if d.get (num1, -1) == -1 :
      d[num1] = 1
      res += 1
    if d.get (num2, -1) == -1 and num2 <= n:
      d[num2] = 1
      res += 1
  print (res)
