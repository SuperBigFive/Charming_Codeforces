for _ in range (int (input ())) :
    n, P, l, t = map (int, input ().split ())
    L, R, study = 1, n, n
    task_cnt = (n + 7 - 1) // 7
    while L <= R :
        mid = (L + R) // 2
        p = l * mid + t * min (2 * mid, task_cnt)
        if p >= P :
            R = mid - 1
            study = mid
        else :
            L = mid + 1
    print (n - study)
