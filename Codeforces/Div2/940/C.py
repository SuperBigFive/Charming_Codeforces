MOD = 10**9 + 7
N = int (3e5) + 5

def QSM (x, p) :
  ans = 1
  while p :
    if p & 1 : ans = ans * x % MOD
    p >>= 1; x = x * x % MOD
  return ans

fac, inv = [1] * N, [1] * N
for i in range (1, N) :
  fac[i] = fac[i - 1] * i % MOD
inv[N - 1] = QSM (fac[N - 1], MOD - 2)
for i in range (N - 2, 0, -1) :
  inv[i] = inv[i + 1] * (i + 1) % MOD

def C (n, m) :
  return fac[n] * inv[m] % MOD * inv[n - m] % MOD

for _ in range (int (input ())) :
  n, k = map (int, input ().split ())
  remain = n
  for i in range (k) :
    r, c = map (int, input ().split ())
    if r == c : remain -= 1
    else : remain -= 2
  ans = 0
  for i in range (remain // 2 + 1) :
    ans = ans + C (remain, i) * (fac[remain - i] * inv[remain - 2 * i] % MOD) % MOD
    ans = ans % MOD
    # print (i, remain, i, C (remain, i))
  print (ans)
