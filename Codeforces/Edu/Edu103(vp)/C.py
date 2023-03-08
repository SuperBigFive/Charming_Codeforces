for t in range (int (input ())) :
    n = int (input ())
    c = list (map (int, input ().split ()))
    a = list (map (int, input ().split ()))
    b = list (map (int, input ().split ()))
    f = [0] * (n + 5); res = 0
    for i in range (1, n) :
        f[i] = c[i] + abs (a[i] - b[i]) + 1
        if i != 1 and a[i] != b[i] :
           f[i] = max (f[i], c[i] + f[i - 1] - (abs (a[i] - b[i]) - 1))
        res = max (res, f[i])
    print (res)

