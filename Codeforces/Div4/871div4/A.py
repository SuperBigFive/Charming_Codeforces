for t in range (int (input ())) :
    s = input (); s2 = "codeforces"
    ans = 0
    for i in range (len (s)) :
        if s[i] != s2[i] : ans += 1
    print (ans)
