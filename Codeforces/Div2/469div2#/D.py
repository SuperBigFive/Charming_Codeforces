n, q = map (int, input ().split ())
for i in range (q) :
    x = int (input ())
    cur = x
    while (cur & 1) == 0 :
        cur = n + cur // 2
    print ((cur + 1) // 2)
