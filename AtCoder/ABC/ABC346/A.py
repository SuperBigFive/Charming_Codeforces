n = int (input ())
a = list (map (int, input ().split ()))
for i in range (n - 1) :
  print (a[i] * a[i + 1], end = ' ' if i < n - 2 else '\n')
