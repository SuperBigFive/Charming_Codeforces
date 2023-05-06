N = 2 ** 8
MOD = 10 ** 9 + 7
for t in range (int (input ())) :
    n, k = map (int, input ().split ())
    dp = list ([0 for j in range (N)] for i in range (2))
    a = [0] + list (map (int, input ().split ()))
    for i in range (1, n + 1) :
        for j in range (N) : dp[i & 1][j] = 0
        for j in range (N) :
            nxt = j & a[i]
            dp[i & 1][j] = (dp[i & 1][j] + dp[(i - 1) & 1][j]) % MOD
            dp[i & 1][nxt] = (dp[i & 1][nxt] + dp[(i - 1) & 1][j]) % MOD
        dp[i & 1][a[i]] += 1
    ans = 0
    for i in range (N) :
        j = i; cnt = 0
        while j : cnt += j % 2; j //= 2
        if cnt == k : ans = (ans + dp[n & 1][i]) % MOD
    print (ans)
