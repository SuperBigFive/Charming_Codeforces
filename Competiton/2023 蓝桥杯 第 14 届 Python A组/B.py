candy = [[0, 0] for i in range (7)]
siz = [0] * 7; suf = [0] * 10
ans = 0

def dfs2 (u, remain) :
  global ans
  if u == 7 : ans += 1; return
  for i in range (0, siz[u] + 1) :
    if i > remain : break
    if remain - i > suf[u + 1] : continue
    dfs2 (u + 1, remain - i)

def dfs1 (u, sum) :
  if u == 7 :
    for i in range (6, -1, -1) : suf[i] = suf[i + 1] + siz[i]
    if sum == 0 : dfs2 (0, 9)
    return
  for i in range (2, 6) :
    if (sum - i) < (7 - u - 1) * 2 : continue
    if (sum - i) > (7 - u - 1) * 5 : continue
    siz[u] = i
    dfs1 (u + 1, sum - i)

dfs1 (0, 26)
print (ans)

print (5002004)
