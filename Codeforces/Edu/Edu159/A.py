for _ in range (int (input ())) :
    n = int (input ())
    s = input ()
    chk = False
    cnt0, cnt1 = 0, 0
    for i in range (n) :
        if i < n - 1 and s[i] == '1' and s[i + 1] == '0' :
            chk = True
        if s[i] == '0' :
            cnt0 += 1
        if s[i] == '1' :
            cnt1 += 1
        if i < n - 1 and s[i] == '0' and s[i + 1] == '1' :
            chk = True
    if cnt0 > cnt1 or chk :
        print ("Yes")
    else :
        print ("No")