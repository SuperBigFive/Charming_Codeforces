import sys
N = int (1e6 + 5)
sys.setrecursionlimit (N)

n, t, tot = [0] * 3
node = [0] * (N << 2);

def ask (l, r) -> int :
  print ("?", l, r)
  sys.stdout.flush ()
  return int (input ())

def ans (k) : print ("!", k)
 
def charming () :
  global n, t, tot, node
  n, t = map (int, input ().split ())
  d = dict (); q = list (); head = 0
  q.append ((1, n)); d[(1, n)] = 1
  tot = 1
  while head < len (q) :
    l, r = q[head]; head += 1
    if l == r : continue
    mid = (l + r) // 2
    d[(l, mid)] = d[(l, r)] * 2
    d[(mid + 1, r)] = d[(l, r)] * 2 + 1
    q.append ((l, mid)); q.append ((mid + 1, r))
  vis = set ()
  for i in range (t) :
    k = int (input ())
    l = 1; r = n;
    while l < r :
      mid = (l + r) // 2
      val_l = int ()
      if (l, mid) in vis : val_l = node[d[(l, mid)]]
      else :
        val_l = mid - l + 1 - ask (l, mid)
        node[d[(l, mid)]] = val_l; vis.add ((l, mid))
      if val_l < k : k -= val_l; l = mid + 1
      else : r = mid
    ans (l)
    cur = d[(l, l)]
    while cur : node[cur] -= 1; cur //= 2
  
charming ()
