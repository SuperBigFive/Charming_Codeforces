for _ in range (int (input ())) :
    n = int (input ())
    l = list (map (int, input ().split ()))
    r = list (map (int, input ().split ()))
    c = list (map (int, input ().split ()))
    l.sort (); r.sort (); c.sort ()
    lhead, ltail = 0, n - 1
    rhead, rtail = 0, n - 1
    a = []
    while lhead <= ltail and rhead <= rtail :
        if lhead < ltail and l[lhead + 1] > r[rhead] :
          a.append (r[rhead] - l[lhead])
          rhead += 1
          lhead += 1
        elif rtail > rhead and r[rtail - 1] < l[ltail] :
           a.append (r[rtail] - l[ltail])
           rtail -= 1
           ltail -= 1
        else :
           a.append (r[rtail] - l[lhead])
           lhead += 1
           rtail -= 1
    a.sort (reverse = True)
    ans = 0
    for i in range (n) :
       ans += c[i] * a[i]
    print (ans)