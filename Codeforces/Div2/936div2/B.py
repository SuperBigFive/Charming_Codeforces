MOD = int (1e9) + 7

def QSM (p, x) :
  ans = 1
  while p :
    if p & 1 : ans = ans * x % MOD
    p >>= 1; x = x * x % MOD
  return ans

for _ in range (int (input ())) :
  n, k = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  sum, ans, res = 0, 0, 0
  for i in range (n) :
    res += a[i]; sum += a[i]
    sum = max (0, sum)
    ans = max (ans, sum)
  ans = ((ans % MOD) + MOD) % MOD
  res = (res + (QSM (k, 2) - 1) * ans % MOD) % MOD
  res = ((res % MOD) + MOD) % MOD
  print (res)
