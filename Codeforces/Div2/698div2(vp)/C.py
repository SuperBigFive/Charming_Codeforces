for t in range (int (input ())) :
    n = int (input ())
    d = list (map (int, input ().split ()))
    cnt = dict ()
    for i in d : 
        if i in cnt : cnt[i] += 1
        else : cnt[i] = 1 
    ok = True; b = list ()
    for key, value in cnt.items () :
        if value != 2 : print ("NO"); ok = False; break
        b.append (key)
    if ok == False : continue
    a = [0] * (n); b.sort (); remain = 0
    for i in range (n - 1, -1, -1) :
        if (b[i] - remain) % (2 * (i + 1)) or \
           b[i] <= remain: ok = False; break
        a[i] = (b[i] - remain) // (2 * (i + 1))
        remain += 2 * a[i];
    for i in range (n) : 
        if i == 0 : 
            if a[i] == 0 : ok = False; break
        elif a[i] == a[i - 1] or a[i] <= 0 : ok = False; break
    print ("YES" if ok else "NO")
    
