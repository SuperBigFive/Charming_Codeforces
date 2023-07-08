q, y = map (int, input ().split ())
for i in range (y, q, -1) :
    p = 2; flag = False
    while p * p <= i :
        if i % p == 0 :
            if p > q : print (i); exit (0)
            else : flag = True; break
        p += 1
    if flag == False : print (i); exit (0)
print (-1)
