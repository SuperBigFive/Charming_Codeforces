for t in range (int (input ())) :
  n = int (input ()); s = input ();
  last = -1; ok = True;
  for i in range (n // 2) :
    if s[i] != s[n - i - 1] :
      if last == -1 or last + 1 == i: last = i
      else : ok = False; break;
  print ("YES" if ok else "NO")
