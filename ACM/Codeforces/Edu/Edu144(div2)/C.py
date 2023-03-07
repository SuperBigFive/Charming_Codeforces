import sys
N = int (1e5 + 5)
sys.setrecursionlimit (N)
mod = 998244353

def C (n, m) :
  res = 1;
  for i in range (1, m + 1) :
    res = (res * (n - i + 1) // i)
  return res % mod

def bisearch (L, R, coef) :
  mx = R; k = L - 1;
  while (L <= R) :
    mid = (L + R) // 2
    if (mid * coef <= mx) :
      L = mid + 1
      k = mid
    else : R = mid - 1
  return k

for t in range (int (input ())) :
  l, r = list (map (int, input ().split ()))
  res = 0; c = 1; cnt = 0; siz = 0
  while (l * c * 2 <= r) :
    c *= 2; siz += 1
  while (True) :
    res = (res + ((bisearch (l, r, c)) - l + 1) * C (siz, cnt)) % mod
    c /= 2; c *= 3; cnt += 1
    if l * c > r : break
  print (siz + 1, ((res % mod) + mod) % mod)
