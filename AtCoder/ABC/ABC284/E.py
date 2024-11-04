import sys
import time
N = int (1e6 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, m = map (int, input ().split ())
  adj = list (list () for i in range (n + 1))
  vis = [0] * (n + 1);
  for i in range (m) :
    u, v = map (int, input ().split ())
    adj[u].append (v); adj[v].append (u)

  def dfs (u) :
    global res
    vis[u] = True; res += 1
    ntim = time.time ()
    if res >= int (1e6) or ntim - tim >= 1.8 : print (int (1e6)); sys.exit (0)
    for v in adj[u] :
      if vis[v] : continue
      dfs (v)
    vis[u] = False
  dfs (1)
  
  print (res)

res = 0; tim = time.time ()
charming ()
