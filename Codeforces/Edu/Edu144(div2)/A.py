import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

s1 = str ()
for i in range (1, 100) :
  if (i % 3 == 0) : s1 = s1 + "F"
  if (i % 5 == 0) : s1 = s1 + "B"
for t in range (int (input ())) :
  n = input (); s2 = input ()
  if (s2 in s1) : print ("YES")
  else : print ("NO")
