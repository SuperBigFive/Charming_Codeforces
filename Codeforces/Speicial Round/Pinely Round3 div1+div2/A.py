for _ in range (int (input ())) :
    n = int (input ())
    mnx, mxx = 101, -101
    mny, mxy = 101, -101
    for i in range (n) :
        x, y = map (int, input ().split ())
        mnx = min (mnx, x)
        mxx = max (mxx, x)
        mny = min (mny, y)
        mxy = max (mxy, y)
    if mnx >= 0 or mxx <= 0 or mny >= 0 or mxy <= 0 :
        print ("YES")
    else :
        print ("NO")