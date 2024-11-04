N = int (1e6) + 5

def find (x, pre) :
  while True :
    if x == pre[x] : return x
    else : x = pre[x]

def merge (x, y, het, pre) :
  if het[x] < het[y] : x, y = y, x
  pre[y] = x
  if het[x] == het[y] : het[x] += 1

n, m = map (int, input ().split ())
edges = []
for i in range (m) :
  k, c = map (int, input ().split ())
  v = list (map (int, input ().split ()))
  edges.append ((k, c, v))
edges.sort (key = lambda x : x[1])
ans = 0
pre = list (range (N))
het = [1] * N
cnt = n - 1
for k, c, v in edges :
  for i in range (k - 1) :
    x, y = v[i], v[i + 1]
    prex = find (x, pre); prey = find (y, pre)
    if prex == prey : continue
    else :
      ans += c
      merge (prex, prey, het, pre)
      cnt -= 1
if cnt > 0 : ans = -1
print (ans)