for t in range (int (input ())) :
  a, b = map (int, input ().split ())
  if a < b :
    c = a
    a = b
    b = c
  a = min (a, b * 3)
  print ((a + b) // 4)
  
  
