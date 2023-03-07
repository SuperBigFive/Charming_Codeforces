N = int (2e5 + 5); P = 7213679; mod = 3154432623543
POWP = [0] * (N); POWP[0] = 1
for i in range (1, N) : POWP[i] = (POWP[i - 1] * P) % mod
for t in range (int (input ())) :
  n = int (input ()); s = ['#'] + list (input ())
  hash_val = [0] * (n + 5)
  for i in range (1, n + 1) :
    hash_val[i] = (hash_val[i - 1] * P + ord (s[i]) - ord ('a') + 1) % mod
  vis = set (); res = 0
  for i in range (1, n) :
    cur = (hash_val[i - 1] - hash_val[i + 1]) * POWP[n - i - 1];
    cur = ((cur % mod) + mod) % mod
    if cur in vis : continue
    res += 1; vis.add (cur)
  print (res)
