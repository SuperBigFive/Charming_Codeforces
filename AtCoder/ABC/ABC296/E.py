import sys
N = (10 ** 6) + 5
sys.setrecursionlimit (N)

n = int (input ())
a = [0] + list (map (int, input ().split ()))

vis = [0] * (n + 5); stk = []; inCircle = [0] * (n + 5)

def dfs (u, id) :
  vis[u] = id
  stk.append (u)
  if vis[a[u]] == id:
    while stk[-1] != a[u] : inCircle[stk[-1]] = 1; stk.pop ()
    inCircle[a[u]] = 1
    stk.clear ()
    return
  elif vis[a[u]] > 0 : return
  else : dfs (a[u], id)

for i in range (1, n + 1) :
  if vis[i] == 0 : dfs (i, i)

ans = 0
for i in range (1, n + 1) :
  if inCircle[i] == 1 : ans += 1
print (ans)
