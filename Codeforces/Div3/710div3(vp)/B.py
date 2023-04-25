import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, k = map (int, input ().split ())
  s = input (); pos = list ();
  for i in range (len (s)) :
    if s[i] == '*' : pos.append (i)
  res = 0; last = pos[0]; i = 1
  if len (pos) <= 1 : print (1); return
  while True :
    j = i
    while j < len (pos) and pos[j] - last <= k : j += 1
    if j == len (pos) : break
    res += 1; i = j; last = pos[j - 1]
  print (res + 2)
    
for t in range (int (input ())) : charming ()
