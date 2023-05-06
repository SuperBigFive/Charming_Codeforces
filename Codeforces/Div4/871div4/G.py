N = 1500
a = list ([(i * (i - 1) // 2 + j) ** 2 for j in range (N)] for i in range (N))
b = list ([0 for j in range (N)] for i in range (N))
ans = list ([(i * (i - 1) // 2 + j) ** 2 for j in range (N)] for i in range (N))
for i in range (1, N) : 
    b[i][1] = a[i][i]
    for j in range (2, N) :
        if i + j - 1 < N : b[i][j] = b[i][j - 1] + a[i + j - 1][i]
for i in range (2, N) :
    ans[i][1] = ans[i - 1][1] + a[i][1]
    for j in range (2, i + 1) :
        ans[i][j] = ans[i - 1][j - 1] + b[j][i - j + 1]

for t in range (int (input ())) :
    n = int (input ())
    row = 1
    while row * (row + 1) // 2 < n : row += 1
    col = n - row * (row - 1) // 2
    print (ans[row][col])
