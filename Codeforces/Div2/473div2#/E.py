N = 60
n = int (input ()); cnt = 0; ans = 0
dp = [0] * N
dp[1] = 1
for i in range (2, N) : dp[i] = dp[i - 1] * 2 + (1 << (i - 1))

tmp = n; flag = False
while tmp :
  if tmp & 1 :
    if flag == False : flag = True
    else :
      ans += 1 << cnt
    if cnt : ans += dp[cnt]
  cnt += 1
  tmp //= 2
print (ans)

