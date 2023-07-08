for t in range (int (input ())) :
    n = int (input ())
    a = list (map (int, input ().split ()))
    pre = [0] * n; suf = [0] * n
    for i in range (n) : pre[i] = pre[i - 1] + a[i]
    mx_suf = 0; p = n; ans = 0; mx_ans = 0
    for i in range (n - 1, 0, -1) :
        if i == n - 1 : suf[i] = a[i]
        else : suf[i] = suf[i + 1] + a[i]
        mx_suf = max (mx_suf, suf[i])
        if max (0, pre[i - 1]) + mx_suf > mx_ans :
            mx_ans = max (0, pre[i - 1]) + mx_suf
            ans = max (0, pre[i - 1])
    if pre[n - 1] > mx_ans : print (pre[n - 1])
    else : print (ans)
