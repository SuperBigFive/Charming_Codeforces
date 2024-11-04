n = int (input ())
s = input ()
c = list (map (int, input ().split ()))
dp = [10 ** 18] * 4
# dp[0] : 非 good 末尾是 0
# dp[1] : 非 good 末尾是 1
# dp[2] : good 末尾是 0
# dp[3] : good 末尾是 1
if s[0] == '0' :
  dp[0] = 0
  dp[1] = c[0]
else :
  dp[0] = c[0]
  dp[1] = 0
for i in range (1, n) :
  ndp = [10 ** 18] * 4
  if s[i] == '0' :
    ndp[3] = min (dp[1] + c[i], dp[2] + c[i])
    ndp[1] = dp[0] + c[i]
    ndp[2] = min (dp[3], dp[0])
    ndp[0] = dp[1]
  else :
    ndp[2] = min (dp[0] + c[i], dp[3] + c[i])
    ndp[0] = dp[1] + c[i]
    ndp[3] = min (dp[2], dp[1])
    ndp[1] = dp[0]
  dp = ndp

print (min (dp[2], dp[3]))