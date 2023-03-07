import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)
n, m = map (int, input ().split ())
pre = list (i for i in range (N + 5))
siz_v = [1] * (N + 5); siz_e = [0] * (N + 5)

def find (x) :
  if x == pre[x] : return x
  pre[x] = find (pre[x])
  return pre[x]

for i in range (m) :
  u, v = map (int, input ().split ())
  fu = find (u); fv = find (v)
  if fu == fv : siz_e[fu] += 1
  else :
    pre[fu] = fv
    siz_v[fv] += siz_v[fu]
    siz_e[fv] += siz_e[fu] + 1
ok = True
for i in range (1, n + 1) :
  if i != pre[i] : continue
  elif siz_v[i] != siz_e[i] : ok = False; break
print ("Yes" if ok else "No")
