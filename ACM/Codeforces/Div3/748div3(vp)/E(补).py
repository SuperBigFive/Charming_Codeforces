import sys
import copy
N = int (1e6 + 5)
sys.setrecursionlimit (N)

n, k = int (), int ()
adj = list ()
    
def charming () :
  global n, k, adj
  input ()
  n, k = map (int, input ().split ())
  adj = list (list () for i in range (n + 1))
  vis = set (); du = [0] * (n + 1)
  for i in range (n - 1) :
    u, v = map (int, input ().split ())
    adj[u].append (v); adj[v].append (u)
    du[u] += 1; du[v] += 1
  leaf = set ()
  for i in range (1, n + 1) :
    if du[i] <= 1 :
      leaf.add (i)
      vis.add (i)
  nleaf = set ()
  for i in range (k - 1) :
    nleaf.clear ()
    for u in leaf :
      for v in adj[u] :
        if v in vis : continue
        du[v] -= 1
        if du[v] <= 1 :
          nleaf.add (v)
          vis.add (v)
    leaf = copy.deepcopy (nleaf)
    if len (leaf) <= 0 : break
  print (n - len (vis))
''''''
for t in range (int (input ())) : charming ()
