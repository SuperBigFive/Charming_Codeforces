import math
for t in range (int (input ())) :
    n, k = map (int, input ().split ())
    a = list (map (int, input ().split ()))
    a.sort (); GCD = a[1] - a[0]
    for i in range (2, n) : GCD = math.gcd (GCD, a[i] - a[1])
    ok = False;
    for i in range (n) :
        delta = abs (k - a[i])
        if delta % GCD == 0 : ok = True; break
    print ("YES" if ok else "NO")
