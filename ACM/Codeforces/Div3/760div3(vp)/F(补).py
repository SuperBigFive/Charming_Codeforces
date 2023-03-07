import sys
x, y = map (int, input ().split ())
x = "{0:b}".format (x)
y = "{0:b}".format (y)
if x == y :
  print ("YES")
  sys.exit (0)
if y[len (y) - 1] == "0" :
  print ("NO")
  sys.exit (0)
be = 0
en = len (x)
while x[be] == "0" : be += 1
while x[en - 1] == "0" : en -= 1
x = [x[be : en], ''.join (reversed (x[be : en])),\
     x + "1", ''.join (reversed (x + "1"))]
sum0 = [0] * len (y)
for i in range (1, len (y)) :
  sum0[i] = sum0[i - 1]
  if y[i] == "0" :
    sum0[i] += 1
get_sum = lambda i, j : sum0[max (0, i - 1)] + sum0[len (y) - 1] == sum0[j -1]
for i in range (len (y)) :
  j = [i + len (x[0]), i + len (x[1]), i + len (x[2]), i + len (x[3])]
  for k in range (4) :
    if j[k] <= len (y) and x[k] == y[i : j[k]] and get_sum (i, j[k]) :
      print ("YES")
      sys.exit (0)
print ("NO")
