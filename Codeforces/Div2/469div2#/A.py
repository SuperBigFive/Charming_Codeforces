l, r, a = map (int, input ().split ())
if l > r : l, r = r, l
if l + a <= r : print (2 * (l + a))
else : print ((r + (a - (r - l)) // 2) * 2)

