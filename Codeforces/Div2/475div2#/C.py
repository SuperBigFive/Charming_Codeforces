MOD = 10 ** 9 + 9
n, a, b, k = map (int, input ().split ())
s = input (); ans = 0

def qsm (x, p) -> int :
  ans = 1
  while p :
    if p & 1 : ans = (ans * x) % MOD
    p //= 2; x = (x * x) % MOD
  return ans

x = qsm (b, k) * qsm (qsm (a, k), MOD - 2) % MOD
y = (n + 1) // k; z = (1 - qsm (x,  y)) * qsm (1 - x, MOD - 2) % MOD
#print (z)
if z == 0 : z = y
ca = qsm (a, n); cb = 1; inva = qsm (a, MOD - 2)
for i in range (k) :
  ans = ans + (1 if s[i] == '+' else -1) * ca * cb * z
  ans = ((ans % MOD) + MOD) % MOD
  ca = ca * inva % MOD; cb = cb * b % MOD
ans = ((ans % MOD) + MOD) % MOD
print (ans)
