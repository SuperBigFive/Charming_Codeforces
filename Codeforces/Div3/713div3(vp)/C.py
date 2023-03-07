import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  a, b = map (int, input ().split ()); s = list (input ())
  pf = 0; pb = len (s) - 1;
  d = dict ({'0' : 0, '1' : 0, '?' : 0})
  while pf < pb :
    if s[pf] == s[pb] : d[s[pf]] += 2;
    elif s[pf] != '?' and s[pb] != '?' : print (-1); return
    elif s[pf] == '1' or s[pb] == '1':
      s[pf if s[pf] == '?' else pb] = '1'
      d['1'] += 2
    else :
      s[pf if s[pf] == '?' else pb] = '0'
      d['0'] += 2
    pf += 1; pb -= 1
  if a < d['0'] or b < d['1'] : print (-1); return
  pf = 0; pb = len (s) - 1
  while pf < pb :
    if s[pf] == s[pb] == '?' :
      if a - 1 > d['0'] : s[pf] = s[pb] = '0' ; d['0'] += 2
      elif b - 1 > d['1'] : s[pf] = s[pb] = '1' ; d['1'] += 2
    pf += 1; pb -= 1
  if (a + b) & 1 :
    half = (a + b) // 2
    if s[half] == '?' and a > d['0'] : s[half] = '0'; d['0'] += 1
    elif s[half] == '?' and b > d['1'] : s[half] = '1'; d['1'] += 1
    else : d[s[half]] += 1
  if a != d['0'] or b != d['1'] : print (-1)
  else :
    for i in s : print (i, end = '')
    print ()
    
for t in range (int (input ())) : charming ()
