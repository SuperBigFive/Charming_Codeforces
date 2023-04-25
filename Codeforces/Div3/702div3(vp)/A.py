import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); a = list (map (int, input ().split ()))
  res = 0
  for i in range (n - 1) :
    if 2 * a[i] < a[i + 1] :
      tmp = a[i]
      while 2 * tmp < a[i + 1] : res += 1; tmp *= 2
    if a[i] > 2 * a[i + 1] :
      tmp = a[i]
      while tmp > 2 * a[i + 1] : res += 1; tmp = (tmp - 1) // 2 + 1
      
  print (res)

for t in range (int (input ())) : charming ()
