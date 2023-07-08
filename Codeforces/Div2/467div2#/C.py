k, d, t = map (int, input ().split ())
if k == d : print (t); exit (0)
x = (k + d - 1) // d
t *= 2
cost = k * 2 + x * d - k
ans = t // cost * x * d
t %= cost
if k * 2 < t : print (ans + k + t - 2 * k); exit (0)
else : print (ans + t / 2)

