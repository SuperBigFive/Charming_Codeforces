for t in range (int (input ())):
  s = input ()
  n = len (s)
  if n & 1 > 0 :
    print ("NO")
    continue
  ok = True;
  for i in range (n // 2) :
    if s[i] != s[i + n // 2] :
      print ("NO")
      ok = False
      break
  if ok == True :
    print ("YES")
    
