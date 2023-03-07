import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, m = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  b = list (map (int, input ().split ()))
  c = list (zip (a, b))
  c.sort (key = lambda x : x[0] / x[1], reverse = True)
  res = 0; last = 0; sum = 0
  for i in range (n) :
    if sum >= m : break
    sum += c[i][0]
    res += c[i][1]
    last = i
  if sum < m : print (-1); return
  if c[last][1] == 1 : print (res); return
  for i in range (last + 1, n) :
    if c[i][1] == 1 and sum - c[last][0] + c[i][0] >= m :
      print (res - 1); return
  for i in range (last) :
    if c[i][1] == 1 and sum - c[i][0] >= m :
      print (res - 1); return
  print (res)
  
for t in range (int (input ())) : charming ()
