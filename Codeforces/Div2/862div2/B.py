for t in range (int (input ())) :
  n = int (input ()); s = input ()
  ch = 'z';
  for i in s : ch = min (ch, i)
  id = n - 1
  while s[id] != ch : id -= 1
  print (ch, end = "")
  for i in range (n) :
    if i == id : continue
    print (s[i], end = "")
  print ()
