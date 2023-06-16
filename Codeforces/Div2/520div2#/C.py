N = 10 ** 5 + 2; MOD = 10 ** 9 + 7
n, q = map (int, input ().split ())
x = input (); pre = [0] * (n + 5)
for i in range (1, n + 1) : pre[i] = pre[i - 1] + (x[i - 1] == '1')
POW2 = [1] * (N); pre2 = [1] * (N)
for i in range (1, N) :
  POW2[i] = (POW2[i - 1] * 2) % MOD
  pre2[i] = (pre2[i - 1] + POW2[i]) % MOD
for i in range (q) :
  l, r = map (int, input ().split ())
  cnt0, cnt1 = r - l + 1 - (pre[r] - pre[l - 1]), pre[r] - pre[l - 1]
  if cnt1 <= 0 : print (0); continue
  ans = pre2[cnt1 - 1]
  if cnt0 > 0 : ans += pre2[cnt0 - 1] * (POW2[cnt1] - 1)
  ans = ((ans % MOD) + MOD) % MOD
  print (ans)
  
