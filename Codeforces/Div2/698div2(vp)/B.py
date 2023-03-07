N = int (1e2 + 5)
for t in range (int (input ())) :
    q, d = map (int, input ().split ())
    a = list (map (int, input ().split ()))
    ok = [0] * (N); ok[0] = 1
    for i in range (1, N) :
        for j in range (1, i + 1) :
            k = j; have_d = False
            while k > 0 :
                if k % 10 == d : have_d = True; break
                k //= 10
            if have_d and ok[i - j] == True : ok[i] = True; break
    for i in range (q) :
        if a[i] < N : print ("YES" if ok[a[i]] else "NO")
        else : print ("YES")
