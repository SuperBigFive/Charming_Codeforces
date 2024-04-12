s = input ()
if s[0] == '<' and s[-1] == '>' :
  ok = True
  for i in range (1, len (s) - 1) :
    if s[i] != '=' :
      ok = False
      break
  if ok : print ('Yes')
  else : print ('No')
else : print ('No')