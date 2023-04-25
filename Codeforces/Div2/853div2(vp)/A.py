import math
for t in range (int (input ())) :
  n = int (input ());
  a = list (map (int, input ().split ()))
  ok = False
  for i in a :
    for j in a :
      if math.gcd (i, j) <= 2 : ok = True; break
    if ok : break
  print ("YES" if ok else "NO")
