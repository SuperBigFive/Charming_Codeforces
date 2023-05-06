import sys
N = 400 * 400 + 5; MOD = 998244353


n, m, k = map (int, input ().split ())
mp = [0] * (n + 5)
for i in range (1, n + 1) :
  mp[i] = '#' + input ()

dp1 = list ([[0] * (n + m + 5) for i in range (m + 5)] for i in range(n + 5))
dp2 = list ([[0] * (n + m + 5) for i in range (m + 5)] for i in range(n + 5))
vis = list ([[0] * (n + m + 5) for i in range (m + 5)] for i in range(n + 5))
if mp[n][m] == 'A' : dp1[n][m][1] = 1; vis[n][m][1] = 1
else : dp1[n][m][0] = 1; vis[n][m][0] = 1

def qsm (x, p) :
  ans = 1
  while p :
    if p & 1 : ans = (ans * x) % MOD
    p //= 2; x = (x * x) % MOD
  return ans

def dfs (x, y, z) :
  if x > n or y > m or z < 0 or z >= n + m + 5 : return
  if vis[x][y][z] : return
  vis[x][y][z] = 1
  if mp[x][y] == 'A' :
    if z == 0 : return
    dfs (x + 1, y, z - 1)
    dfs (x, y + 1, z - 1)
    dp1[x][y][z] = (dp1[x + 1][y][z - 1] + dp1[x][y + 1][z - 1]) % MOD
    if z < k : dp2[x][y][z] = (dp2[x + 1][y][z - 1] + dp2[x][y + 1][z - 1]) % MOD
    else : dp2[x][y][z] = (dp1[x + 1][y][z - 1] + dp2[x + 1][y][z - 1] + \
                        dp1[x][y + 1][z - 1] + dp2[x][y + 1][z - 1]) % MOD
  else :
    if z > 0 : return
    for i in range (n + m + 5) :
      dfs (x + 1, y, i)
      dfs (x, y + 1, i)
      dp1[x][y][0] = (dp1[x][y][0] + dp1[x + 1][y][i] + dp1[x][y + 1][i]) % MOD
      #print (x, y, z, i, dp2[x][y][0], dp2[x + 1][y][i], dp2[x][y + 1][i])
      dp2[x][y][0] = (dp2[x][y][0] + dp2[x + 1][y][i] + dp2[x][y + 1][i]) % MOD

fac = [1] * (n + m + 5); inv = [1] * (n + m + 5)
for i in range (1, n + m + 5) :
  fac[i] = (fac[i - 1] * i) % MOD
  inv[i] = qsm (fac[i], MOD - 2)
ans = 0
ans_inv = (((fac[n + m - 2] * inv[n - 1]) % MOD) * inv[m - 1]) % MOD
ans_inv = qsm (ans_inv, MOD - 2)
if mp[1][1] == 'A' :
  for i in range (1, n + m + 5) :
    dfs (1, 1, i)
    ans = (ans + dp2[1][1][i]) % MOD
else : dfs (1, 1, 0); ans = dp2[1][1][0]
ans = (ans * ans_inv) % MOD
ans = ((ans % MOD) + MOD) % MOD
print (ans)
          
  
