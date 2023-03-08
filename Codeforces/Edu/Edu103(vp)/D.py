for t in range (int (input ())) :
    n = int (input ())
    fl = [0] * (n + 5); fr = [0] * (n + 5)
    a = input ()
    for i in range (1, n + 1) :
        if a[i - 1] == 'L' :
            if i == 1 : fl[i] = 1
            elif a[i - 2] == 'L' : fl[i] = 1
            else : fl[i] = fl[i - 2] + 2
        else : fl[i] == 0
    for i in range (n - 1, -1, -1) :
        if a[i] == 'R' :
            if i == n - 1 : fr[i] = 1
            elif a[i + 1] == 'R' : fr[i] = 1
            else : fr[i] = fr[i + 2] + 2
        else : fr[i] = 0
    for i in range (n + 1) : print (fl[i] + fr[i] + 1, end = " ")
    print ()

