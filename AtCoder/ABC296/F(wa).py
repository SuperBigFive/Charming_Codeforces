n = int (input ())
a = [0] + list (map (int, input ().split ()))
b = [0] + list (map (int, input ().split ()))

fol_a = [[] for i in range (n + 5)]
cnt_a, cnt_b = dict (), dict ()
p = [0] * (n + 5); q = [0] * (n + 5)
for i in range (1, n + 1) :
  fol_a[a[i]].append ([b[i], i])
  cnt_a[a[i]] = cnt_a.get (a[i], 0) + 1
  cnt_b[b[i]] = cnt_b.get (b[i], 0) + 1

for i in range (1, n + 1) :
  if cnt_a.get (i, 0) :
    if cnt_b.get (i, 0) == 0 : print ("No"); exit (0)
    elif cnt_b[i] != cnt_a[i] : print ("No"); exit (0)
    q[i] = cnt_a[i]

#print (fol_a)
vis = [0] * (n + 5)
for i in range (1, n + 1) :
  if vis[i] : continue
  cnt = 0; cur = a[i]; vis[i] = 1
  while p[cur] < q[cur] :
    p[cur] += 1
    vis[fol_a[cur][p[cur] - 1][1]] = 1
    cur = fol_a[cur][p[cur] - 1][0]
    cnt += 1
  if cnt & 1 : continue
  else : print ("No"); exit (0)

print ("Yes")
