import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

n = int ()

def charming () :
  global n
  n = int (input ())
  a = list (map (int, input ().split ()))
  s = input ()
  red = list (); blue = list ()
  for i in range (n) :
    if s[i] == "R" : red.append (a[i])
    else : blue.append (a[i])
  red.sort (reverse = True); blue.sort ()
  p1 = n + 1; p2 = 0
  ok = True
  for i in red :
    if p1 <= i : ok = False; break
    else : p1 -= 1
  for i in blue :
    if p2 >= i : ok = False; break
    else : p2 += 1
  print ("YES" if ok == True and p1 == p2 + 1 else "NO")
  
for t in range (int (input ())) : charming ()
