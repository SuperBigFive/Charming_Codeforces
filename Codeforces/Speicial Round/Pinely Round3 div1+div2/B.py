for _ in range (int (input ())) :
    n = int (input ())
    a = list (map (int, input ().split ()))
    k = 2
    while True :
        s = set ()
        for x in a :
            s.add (x % k)
        if len (s) == 2 :
            print (k)
            break
        else :
            k *= 2
            