M = 10 ** 4 + 5; MOD = 998244353
n, m = map (int, input ().split ())
dp = [[0 for i in range (M)] for j in range (2)]

def get_num (a, b, c, d) : return a * 1000 + b * 100 + c * 10 + d;
def get_nxt (a, b) : return (a * 10) % 10000 + b; 
ans = 0
dsum = [0] * (M)
for i in range (M) :
  j = i
  while j : dsum[i] += j % 10; j //= 10

for i in range (0, 10) :
  for j in range (0, 10) :
    for k in range (0, 10) :
      for p in range (0, 10) :
        if i & 1 and j & 1 == 0 and k & 1 and p & 1 == 0:
          if i + j + k + p <= m :
            #print (i, j, k, p, get_num (i, j, k, p))
            dp[0][get_num (i, j, k, p)] += 1
        else : continue
for i in range (4, n) :
  for p in range (M) :
    for j in range (10) :
      if (i & 1) == (j & 1) : continue
      if dp[i & 1][p] == 0 or dsum[p] + j > m : dp[i & 1][p] = 0; continue
      nxt = get_nxt (p, j)
      dp[(i + 1) & 1][nxt] = (dp[(i + 1) & 1][nxt] + dp[i & 1][p]) % MOD
    dp[i & 1][p] = 0
for i in range (M) :
  #if dp[n & 1][i] : print (i)
  ans = (ans + dp[n & 1][i]) % MOD
print (ans)

'''nans = 0
d = [0] * (n + 5)

def dfs (u, lim) :
  global nans
  if u > lim :
    s = 0
    #print (d)
    for i in range (1, lim + 1) : s += d[i]
    if s <= m : nans += 1
    return
  for i in range (10) :
    if (i & 1) ^ (u & 1) : continue
    d[u] = i
    dfs (u + 1, lim)
  
dfs (1, n)
print (nans)'''

      
        
  
