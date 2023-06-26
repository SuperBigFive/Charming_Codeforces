n = int (input ())
if n < 6 : print (-1)
else :
  print (1, 2)
  print (2, 3)
  print (3, 4)
  for i in range (5, n + 1) :
    if i & 1 : print (3, i)
    else : print (2, i)
for i in range (2, n + 1) : print (i - 1, i)
