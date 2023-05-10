for t in range (int (input ())) :
    a, b, c = map (int, input ().split ())
    if b > c : b, c = c, b
    if a > b : a, b = b, a
    if b > c : b, c = c, b
    print (max (1, c - b - a + 1))
