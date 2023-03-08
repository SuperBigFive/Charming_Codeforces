for t in range (int (input ())) :
    n, k = map (int, input ().split ())
    if k < n : print (2 if n % k else 1)
    elif k % n == 0 : print (k // n)
    else : print (k // n + 1)
