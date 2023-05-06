for t in range (int (input ())) :
    n = int (input ())
    mn01 = mn10 = mn11 = 10 ** 9
    for i in range (n) :
        m, val = input ().split ()
        m = int (m)
        if val == '00' : continue
        elif val == '01' : mn01 = min (mn01, m)
        elif val == '10' : mn10 = min (mn10, m)
        else : mn11 = min (mn11, m)
    ans = min (mn01 + mn10, mn11)
    if ans >= 10 ** 9 : print (-1)
    else : print (ans)
