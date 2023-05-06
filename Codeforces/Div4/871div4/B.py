for t in range (int (input ())) :
    n = int (input ())
    a = list (map (int, input ().split ()))
    i, j, ans = 0, 0, 0
    while i < n :
        if a[i] == 1 : i += 1
        else :
            j = i
            while j < n and a[j] == 0 : j += 1
            ans = max (ans, j - i)
            i = j
    print (ans)
