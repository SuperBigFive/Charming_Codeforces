N = int (1e5) + 5
dp = [int (1e9)] * N 
dp[0] = 0
coin = [1, 3, 6, 10, 15]
for i in range (1, N) :
  for x in coin :
    if x <= i :
      dp[i] = min (dp[i], dp[i - x] + 1)

# print (dp[:100])
for _ in range (int (input ())) :
  n = int (input ())
  ans = (n // 15) + (dp[n % 15])
  for i in range (100) :
    ans = min (ans, max (0, n // 15 - i) + dp[min (n, (n % 15) + 15 * i)])
  print (ans)