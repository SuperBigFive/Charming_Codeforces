for t in range (int (input ())) :
    n = int (input ())
    a = list (map (int, input ().split ()))
    for i in range (n) :
        l = 1; r = i + 1; k = 0
        while l <= r :
            mid = (l + r) // 2
            if a[i - mid + 1] >= mid :
                l = mid + 1
                k = mid
            else : r = mid - 1
        print (k, end = " ")
    print ()

