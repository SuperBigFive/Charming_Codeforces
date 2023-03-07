import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  s = input (); alpha = set (); a = list ()
  for i in range (len (s)) :
    if s[i] in alpha : print ("NO"); return
    alpha.add (s[i]); a.append (ord (s[i]) - ord ('a') + 1)
  p1 = 0; p2 = len (s) - 1; cur = len (s)
  while p1 <= p2 :
    if a[p1] == cur : p1 += 1; cur -= 1;
    elif a[p2] == cur : p2 -= 1; cur -= 1;
    else : print ("NO"); return
  print ("YES")
  
  
for t in range (int (input ())) : charming ()
