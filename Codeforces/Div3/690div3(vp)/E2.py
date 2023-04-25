import sys
N = int (2e5 + 5)
mod = int (1e9 + 7)
#sys.setrecursionlimit (N)

fac = [0] * (N); inv = [0] * (N)

def qsm (num, p) -> int :
  res = 1
  while p :
    if p & 1 : res = (res * num) % mod
    p //= 2; num = (num * num) % mod
  return res % mod

def get () :
  fac[0] = inv[0] = 1
  for i in range (1, N) :
    fac[i] = (fac[i - 1] * i) % mod
    inv[i] = qsm (fac[i], mod - 2)

def C (n, m) -> int :
  if n < m : return 0
  return fac[n] * inv[m] * inv[n - m] % mod

def charming () :
  n, m, k = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  res = 0; cnt = [0] * (n + 1)
  if m == 1 : print (n); return
  for i in a : cnt[i] += 1
  for i in range (1, n + 1) : cnt[i] += cnt[i - 1]
  p = 1;
  while p <= n :
    res = (res + C (cnt[min (n, p + k)] - cnt[p - 1], m) \
           - C (cnt[min (n, p + k)] - cnt[p], m)) % mod
    p += 1
  print (res)
    
get ()
for t in range (int (input ())) : charming ()

