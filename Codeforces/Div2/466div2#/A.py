n, d = map (int, input ().split ())
x = list (map (int, input ().split ()))
ans = n - 1
x.sort ()
for i in range (n) :
    for j in range (i + 1, n + 1) :
        nx = x[i : j]
        mn = 101; mx = -1
        for k in nx : mn = min (mn, k); mx = max (mx, k)
        if mx - mn <= d : ans = min (ans, n - (j - i))
print (ans)
