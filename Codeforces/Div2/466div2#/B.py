n = int (input ()); k = int (input ())
A = int (input ()); B = int (input ())
if k == 1 : print (A * (n - 1)); exit (0)
cost = 0
while n > 1 :
    nxt = n // k * k
    nxt = max (1, nxt)
    cost += (n - nxt) * A
    n = nxt
    if n <= 1 : break
    nxt = n // k
    if (n - nxt) * A < B : cost += (n - 1) * A; break
    else : cost += B; n = nxt
print (cost)
