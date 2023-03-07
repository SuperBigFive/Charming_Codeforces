import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  a = input (); b = input ()
  n = len (a); m = len (b)
  if (a[0] == b[0]) :
    print ("YES")
    print (a[0], end = "")
    print ("*")
  elif (a[n - 1] == b[m - 1]) :
    print ("YES")
    print ("*", end = "")
    print (a[n - 1])
  else :
    c = "abcdefghijklmnopqrstuvwxyz"
    for i in c :
      for j in c :
        ns = i + j
        if (ns in a and ns in b) :
          print ("YES")
          print ("*", end = "")
          print (ns, end = "")
          print ("*")
          return
    print ("NO")
  
for t in range (int (input ())) : charming ()
