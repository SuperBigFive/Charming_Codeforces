for i in range (int (input ())) :
    n = int (input ())
    a = list (map (int, input ().split ()))
    i = 0; res = 1
    while i < n :
        j = i
        while j < n and a[j] == a[i] : j += 1
        res = max (res, j - i)
        i = j
    print (res)
