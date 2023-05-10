for t in range (int (input ())) :
    n, m = map (int, input ().split ())
    a = [list (map (int, input ().split ())) for i in range (n)]
    ans = 0
    for i in range ((n + 1) // 2) :
        for j in range ((m + 1) // 2) :
            b = [a[i][j], a[i][m - j - 1], \
                    a[n - i - 1][j], a[n - i - 1][m - j - 1]]
            mn = 10 ** 10
            for k in b :
                cur = 0
                for p in b :
                    cur += abs (k - p)
                if i == n - i - 1 : cur //= 2
                if j == m - j - 1 : cur //= 2
                mn = min (mn, cur)
            ans += mn
    print (ans)
