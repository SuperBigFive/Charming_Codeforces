import sys
N = int (2e3 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, k = map (int, input ().split ())
  a = [0] + list (map (int, input ().split ()))
  dp = list ([0, N] for i in range (n + 1))
  dp[0] = [0, 0]; res = N
  for i in range (1, n + 1) :
    if i - a[i] < 0 : continue
    dp[i][1] = i - a[i]
    for j in range (i) :
      if dp[j][1] > i - a[i] or a[j] >= a[i] : continue
      dp[i][0] = max (dp[i][0], dp[j][0] + 1)
    if dp[i][0] >= k : res = min (res, dp[i][1])
  print (res if res < N else -1)
   
for t in range (int (input ())) : charming ()
