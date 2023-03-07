import sys
N = int (1e3 + 5)
mod = int (1e9 + 7)
sys.setrecursionlimit (N)
fac = [0] * (N); inv = [0] * (N)

def qsm (num, p) -> int :
  res = 1
  while p :
    if p & 1 : res = (res * num) % mod
    p //= 2
    num = (num * num) % mod
  return res

def get () :
  fac[0] = inv[0] = 1
  for i in range (1, N) :
    fac[i] = (fac[i - 1] * i) % mod
    inv[i] = qsm (fac[i], mod - 2)

def C (n, m) -> int :
  if n < m : return 0
  return fac[n] * inv[m] * inv[n - m] % mod

def charming () :
  n, k = map (int, input ().split ())
  a = list (map (int, input ().split ()))
  cnt = dict ()
  for i in a :
    if i not in cnt : cnt[i] = 1
    else : cnt[i] += 1
  a.sort (reverse = True)
  len = 1
  while k - len - 1 >= 0 and a[k - len - 1] == a[k - 1] : len += 1
  print (C (cnt[a[k - 1]], len))

get ()
for t in range (int (input ())) : charming ()
