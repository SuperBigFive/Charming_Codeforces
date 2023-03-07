import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  pos = list (dict () for i in range (n + 1))
  for i in range (n) :
    p = list (map (int, input ().split ()))
    for j in range (n - 1) :
      if j not in pos[p[j]] : pos[p[j]][j] = 1
      else : pos[p[j]][j] += 1
  ans = [0] * n
  for i in range (1, n + 1) :
    key = list (pos[i].keys ())
    if len (key) == 1 :
      ans[0 if key[0] == 0 else n - 1] = i
    else :
      if pos[i][key[0]] == pos[i][key[1]] : ans[n // 2] = i
      elif pos[i][key[0]] == n - key[0] - 1 and key[0] > key[1]: ans[key[0]] = i
      else : ans[key[1]] = i
  for i in ans : print (i, end = " ")
  print ()

for t in range (int (input ())) : charming ()
