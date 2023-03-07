import math
for t in range (int (input ())) :
  n, k = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  a = sorted (a, reverse = True)
  res = sum (a[2 * k : n])
  d = dict ()
  mx = -1
  for i in range (0, 2 * k) :
    if a[i] in d : d[a[i]] += 1
    else : d[a[i]] = 1
    mx = max (mx, d[a[i]])
  print (res + (0 if mx <= k else mx - k))
