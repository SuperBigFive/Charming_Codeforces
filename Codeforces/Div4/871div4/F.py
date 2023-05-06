for t in range (int (input ())) :
    n, m = map (int, input ().split ())
    du = [0] * (n + 5)
    for i in range (m) :
        u, v = map (int, input ().split ())
        du[u] += 1; du[v] += 1
    cnt = dict ()
    for i in range (1, n + 1) : 
        cnt[du[i]] = cnt.get (du[i], 0) + 1
    x, y = -1, -1
    for i in cnt.keys () :
        if cnt[i] == 1 : x = i
        elif i != 1 : y = i - 1 
    if x == -1 : x = y + 1
    print (x, y)
