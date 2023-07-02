n, m = map (int, input ().split ())
x = list (map (int, input ().split ()))
y = list (map (int, input ().split ()))
prex = [0] * n; prey = [0] * m
for i in range (n) : prex[i] = prex[i - 1] + x[i]
for i in range (m) : prey[i] = prey[i - 1] + y[i]
p = 0; ans = 0
for i in range (n) :
    while p + 1 < m and prey[p + 1] <= prex[i] : p += 1
    if prex[i] == prey[p] : ans += 1
print (ans)
