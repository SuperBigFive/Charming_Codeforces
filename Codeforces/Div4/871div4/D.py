for i in range (int (input ())) :
    n, m = map (int, input ().split ())
    q = list (); q.append (n); head = tail = 0
    ok = False
    while head <= tail :
        cur = q[head]; head += 1
        if cur == m : ok = True; break
        elif cur % 3 : continue
        else :
            if (cur // 3) > m : q.append (cur // 3); tail += 1
            elif cur // 3 == m : ok = True; break
            if (cur // 3 * 2) > m : q.append (cur // 3 * 2); tail += 1
            elif (cur // 3 * 2) == m : ok = True; break
    if ok : print ("YES")
    else : print ("NO")



