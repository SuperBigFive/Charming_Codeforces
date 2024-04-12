N = int (2e5) + 5
MOD = int (1e9) + 7

def QSM (x, p) :
  ans = 1
  while p :
    if p & 1 : ans = ans * x % MOD
    p >>= 1; x = x * x % MOD
  return ans

fac = [1] * N
inv = [1] * N
for i in range (1, N) :
  fac[i] = fac[i - 1] * i % MOD
inv[N - 1] = QSM (fac[N - 1], MOD - 2)
for i in range (N - 2, 0, -1) :
  inv[i] = inv[i + 1] * (i + 1) % MOD

def C (n, m) :
  return fac[n] * inv[m] % MOD * inv[n - m] % MOD

def Solve (n, p) :
  ans = 1
  for i in range (len (p) - 1, -1, -1) :
    k = p[i]
    ans = ans * C (n - 1, k - 1) % MOD * fac[n - k] % MOD
    n = p[i] - 1
  return ans

for _ in range (int (input ())) :
  n, m1, m2 = map (int, input ().split ())
  p = list (map (int, input ().split ()))
  s = list (map (int, input ().split ()))
  if p[-1] != s[0] or p[0] != 1 or s[-1] != n : 
    print (0)
    continue
  else :
    m = n - p[-1]
    ans = C (n - 1, p[-1] - 1)
    ans_left = Solve (p[-1] - 1, p[: len (p) - 1])
    q = []
    for i in range (m2 - 1, 0, -1) :
      q.append (n - s[i] + 1)
    ans_right = Solve (m, q)
    ans = ans * ans_left % MOD * ans_right % MOD
    ans = ((ans % MOD) + MOD) % MOD
    print (ans)