for t in range (int (input ())) :
  n = int (input ()); s = list (input ())
  s1 = ['0'] * n; cnt1 = 0
  for i in range (1, n) :
    if s1[i - 1] == s[i - 1] : s1[i] = '0'
    else : s1[i] = '1'; cnt1 += 1
  s2 = ['1'] * n; cnt2 = 1
  for i in range (1, n) :
    if s2[i - 1] == s[i - 1] : s2[i] = '0'
    else : s2[i] = '1'; cnt2 += 1
  print (max (cnt1, cnt2))
