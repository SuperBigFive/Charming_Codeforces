import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

ans = [0] * (N)

def charming () :
  n = int (input ()); m = 3; k = 2
  a = list (map (int, input ().split ()))
  res = 0; cnt = [0] * (n + 1)
  if n < 3 : print (0); return
  for i in a : cnt[i] += 1
  for i in range (1, n + 1) : cnt[i] += cnt[i - 1]
  p = 1;
  while p <= n :
    while p < n and cnt[p] == cnt[p - 1] : p += 1
    res += ans[cnt[(p + k if p + k < n else n)] - cnt[p - 1]]
    res -= ans[cnt[(p + k if p + k < n else n)] - cnt[p]]
    p += 1
  print (res)

for i in range (3, N) : ans[i] = i * (i - 1) * (i - 2) // 6
for t in range (int (input ())) : charming ()

