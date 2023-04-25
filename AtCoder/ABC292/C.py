N = int (2e5 + 5)
f = [0] * (N)
for i in range (1, N) :
  j = i
  while j < N :
    f[j] += 1
    j += i
n = int (input ())
res = 0
for i in range (1, n + 1) :
  res += f[i] * f[n - i]
print (res)
