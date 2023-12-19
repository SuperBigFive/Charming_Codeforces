import math
for _ in range (int (input ())) :
    n = int (input ())
    a = list (map (int, input ().split ()))
    a.sort ()
    vis = set (a)
    gcd = 0
    for i in range (1, n) :
        gcd = math.gcd (gcd, a[i] - a[i - 1])
    ans = 0
    for i in range (n - 1) :
        ans += (a[-1] - a[i]) // gcd
    x = a[-1] - gcd
    ans += 1
    if gcd == 0 :
        print (n)
    else :
        while x in vis :
            ans += 1
            x -= gcd
        print (ans)

# 1 2 3 : 2 + 1 = 3
# 1 2 3 4 : 3 + 2 + 1 = 6