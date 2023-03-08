for t in range (int (input ())) :
    n, k = map (int, input ().split ())
    p = list (map (int, input ().split ()))
    Sum = p[0]; res = 0
    for i in range (1, n) :
        res = max (res, (p[i] * 100 - 1 + k) // k - Sum)
        Sum += p[i]
    print (res)
