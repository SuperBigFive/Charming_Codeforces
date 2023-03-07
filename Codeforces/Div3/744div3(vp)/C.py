import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, m, k= map (int, input ().split ())
  s = list (list () for i in range (n + 1))
  ok = list ([0] * (m + 1) for i in range (n + 1))
  for i in range (1, n + 1) :
    s[i] = '#' + input ()
  for i in range (k, n + 1) :
    for j in range (i + 1, n + 1) :
      for k in range (i + 1, m - i + 1) :
        flag = True
        for h in range (i + 1) :
          if s[j - h][k - h] != '*' \
            or s[j - h][k + h] != '*' :
            flag = False
            break
        if flag == False : continue
        for h in range (i + 1) :
          ok[j - h][k - h] = 1;
          ok[j - h][k + h] = 1;
  for i in range (1, n + 1) :
    for j in range (1, m + 1) :
      if ok[i][j] == 0 and s[i][j] == '*' :
        print ("NO")
        return
  print ("YES")
  
for t in range (int (input ())) : charming ()
