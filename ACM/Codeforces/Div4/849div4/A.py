import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  ch = input (); s = "codeforces"
  for i in s :
    if ch == i :
      print ("YES")
      return
  print ("NO")

for t in range (int (input ())) : charming ()
