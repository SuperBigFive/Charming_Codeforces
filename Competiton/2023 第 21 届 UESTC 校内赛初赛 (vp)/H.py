N = 5 * (10 ** 5) + 5
n, q = map (int, input ().split ())
node = [0] * (N)

def lowbit (x) : return x & -x

def modify (x, k) :
  while x < N : node[x] += k; x += lowbit (x)

def query (x) :
  res = 0
  while x : res += node[x]; x -= lowbit (x)
  return res

pre = [0] * (n + 5); nxt = [0] * (n + 5)
for i in range (1, n + 1) : pre[i] = i - 1; nxt[i] = i + 1; modify (i, 1)
pre[1] = n; nxt[n] = 1; siz = n; cur = 1
for i in range (q) :
  k = int (input ())
  k = (k - 1) % siz + 1
  remain = query (n) - query (cur - 1)
  l, r, p = cur, n, cur
  if remain < k :k -= remain; l = 1; r = cur - 1; p = l; cur = 1
  while l <= r :
    mid = (l + r) // 2
    remain = query (mid) - query (cur - 1)
    if remain >= k : r = mid - 1; p = mid
    else : l = mid + 1
  pre[nxt[p]] = pre[p]; nxt[pre[p]] = nxt[p]
  modify (p, -1); cur = nxt[p]; siz -= 1; print (p)
