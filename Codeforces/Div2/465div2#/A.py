n = int (input ())
ans = 0
i = 1
while i * i <= n :
    if n % i == 0 : ans += 2 - (i * i == n)
    i += 1
print (ans - 1)
