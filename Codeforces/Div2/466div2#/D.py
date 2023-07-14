N = 10 ** 9
n = int (input ())
a = list (map (int, input ().split ()))
b = input ()
p = 4; l, r = -N, N
while p < n :
    if b[p] == '1' and b[p - 1] == '0' :
        l = max (l, max (a[p - 4 : p + 1]) + 1)
        p += 4
    elif b[p] == '0' and b[p - 1] == '1' :
        r = min (r, min (a[p - 4 : p + 1]) - 1)
        p += 4
    elif b[p] == '1' :
        #r = min (r, min (a[p - 4 : p + 1]))
        p += 1
    else :
        #l = max (l, max (a[p - 4 : p + 1]))
        p += 1
print (l, r)
