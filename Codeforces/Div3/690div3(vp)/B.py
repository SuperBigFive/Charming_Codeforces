import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); s = input ()
  for i in range (5) :
    ns = s[0 : i] + s[n - (4 - i): n]
    if ns == "2020" :
      print ("YES")
      return
  print ("NO")
  
for t in range (int (input ())) : charming ()

