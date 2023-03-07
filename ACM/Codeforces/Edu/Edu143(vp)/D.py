N = int (3e5 + 5)
mod = 998244353

def qsm (num, p) -> int :
  res = 1
  while p :
    if p & 1 : res = (res * num) % mod
    p //= 2
    num = (num * num) % mod
  return res

fac = [0] * N; fac[0] = 1
for i in range (1, N) : fac[i] = (fac[i - 1] * i) % mod

n = int (input ())
w = list (map (int, input ().split ()))
res = 1
for i in range (1, n // 3 + 1) :
  wet = w[(i - 1) * 3 : (i - 1) * 3 + 3]
  wet.sort ()
  if wet[0] != wet[1] : continue
  elif wet[1] != wet[2] : res = (res * 2) % mod
  else : res = (res * 3) % mod
res = (res * (fac[n // 3] * qsm (fac[n // 6], mod - 2)) % mod *\
      qsm (fac[n // 6], mod - 2)) % mod
res = ((res % mod) + mod) % mod
print (res)
