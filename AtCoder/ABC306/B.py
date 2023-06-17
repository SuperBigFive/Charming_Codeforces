b = list (map (int, input ().split ())); a = 0
for i in range (64) : a += b[i] * (1 << i)
print (a)
