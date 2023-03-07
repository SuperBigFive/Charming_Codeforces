import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

for t in range (int (input ())) :
  n, m = map (int, input ().split ())
  s1 = list (input ()); s2 = list (input ())

  def check (s1, s2) -> int:
    for i in range (len (s1) - 1) :
      if s1[i] == s1[i + 1] : return 0
    for i in range (len (s2) - 1) :
      if s2[i] == s2[i + 1] : return 0
    return 1
  
  while m >= 2 :
    s1 += s2[m - 1]; s2.pop ();
    n += 1; m -= 1
  ok = False
  while n >= 2 :
    if check (s1, s2) : ok = True; break
    #print (s1, s2)
    s2 += s1[n - 1]; s1.pop ()
    n -= 1; m += 1
  print ("YES" if ok or check (s1, s2) else "NO")
