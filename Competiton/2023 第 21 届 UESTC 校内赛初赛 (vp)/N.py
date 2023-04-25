import math
N = 10 ** 6 + 5; MOD = 998244353
ans = [[0, 0]] * N
fac = [[] for i in range (N)];
POW2 = [0] * N; inv = [0] * N

def qsm (x, p) :
  ans = 1
  while p :
    if p & 1 : ans = (ans * x) % MOD
    p //= 2; x = (x * x) % MOD
  return ans

POW2[0] = inv[0] = 1
for i in range (1, N) :
  POW2[i] = (POW2[i - 1] * 2) % MOD
  inv[i] = qsm (i, MOD - 2)

for i in range (1, N) :
  j = i
  while j < N : fac[j].append (i); j += i

ans[1] = [0, 1]
for i in range (2, N) :
  dp1 = 0; dp2 = 0
  for j in fac[i] :
    dp1 = (dp1 + ans[j][1]) % MOD
    dp2 = (dp2 + ans[j][1] * max (2, j)) % MOD
  dp2 = (POW2[i] - dp2) * inv[i] % MOD
  ans[i] = [dp1, dp2]
      
for t in range (int (input ())) :
  n, k = map (int, input ().split ())
  n = math.gcd (n, k)
  res = ans[n][0] + ans[n][1] + 1
  res = ((res % MOD) + MOD) % MOD
  print (res)
