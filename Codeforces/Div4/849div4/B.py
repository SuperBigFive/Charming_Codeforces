import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); move = input ()
  cx = cy = 0
  for i in move :
    if i == 'U' : cy += 1
    elif i == 'D' : cy -= 1
    elif i == 'R' : cx += 1
    else : cx -= 1
    if cx == 1 and cy == 1 :
      print ("YES")
      return
  print ("NO")

for t in range (int (input ())) : charming ()
