for t in range (int (input ())) :
  a, s = map (str, input ().split ())
  a = ''.join (reversed (a))
  s = ''.join (reversed (s))
  len_a = len (a)
  len_s = len (s)
  j = 0
  b = list ()
  ok = True
  for i in range (len_a) :
    if j >= len_s :
      ok = False
      break
    num_a = int (a[i])
    num_s = int (s[j])
    if num_a > num_s :
      if j + 1 >= len_s or int (s[j + 1]) != 1 :
        ok = False
        break
      b.append (num_s + 10 - num_a)
      j += 2
    else :
      b.append (num_s - num_a)
      j += 1
  if ok == False:
    print (-1)
    continue
  while j < len_s :
    b.append (int (s[j]))
    j += 1
  while len (b) > 1 and b[len (b) - 1] == 0 :
    b.pop ()
  b = reversed (b)
  for i in b :
    print (i, end = "")
  print ("\n")
