for t in range (int (input ())) :
    xa, ya = map (int, input ().split ())
    xb, yb = map (int, input ().split ())
    xc, yc = map (int, input ().split ())
    ans = 1; ok = 0
    if (xb - xa) * (xc - xa) >= 0 :
        ans += min (abs (xb - xa), abs (xc - xa))
    if (yb - ya) * (yc - ya) >= 0 :
        ans += min (abs (yb - ya), abs (yc - ya)) + ok
    print (max (1, ans))
