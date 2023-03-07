for t in range (int (input ())) :
    n = int (input ())
    a = list (map (str, input ().split ()))
    mx_len = n - 1
    b = list ()
    for s in a :
        if len (s) == mx_len :
            b.append (s)
    ok = True
    for i in range (mx_len) :
        if b[0][i] != b[1][mx_len - i - 1] :
            ok = False
            break
    print ("YES" if ok else "NO")

