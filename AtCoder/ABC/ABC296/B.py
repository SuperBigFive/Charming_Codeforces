for i in range (8) :
  s = input ()
  for j in range (8) :
    if s[j] == '*' : print (chr(ord ('a') + j) + str (8 - i))
