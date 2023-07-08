for t in range (int (input ())) :
    n, k, x = map (int, input ().split ())
    if x != 1 :
        print ("YES")
        print (n)
        for i in range (n) : print (1, end = " ")
        print ()
    elif k == 1 : print ("NO")
    elif n & 1 :
        if k == 2 or n == 1 : print ("NO")
        else :
            print ("YES")
            print (n // 2)
            print (3, end = " ")
            for i in range (n // 2 - 1) : print (2, end = " ")
            print ()
    else :
        print ("YES")
        print (n // 2)
        for i in range (n // 2) : print (2, end = " ")
        print ()
