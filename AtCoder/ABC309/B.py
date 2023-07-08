import copy
n = int (input ())
a = list ()
for i in range (n) : a.append (list (input ()))
b = copy.deepcopy (a)
for i in range (1, n - 1) :
    b[0][i] = a[0][i - 1]
    b[i][n - 1] = a[i - 1][n - 1]
    b[n - 1][i] = a[n - 1][i + 1]
    b[i][0] = a[i + 1][0]
b[0][0] = a[1][0]
b[0][n - 1] = a[0][n - 2]
b[n - 1][0] = a[n - 1][1]
b[n - 1][n - 1] = a[n - 2][n - 1]
for i in range (n) :
    for j in range (n) :
        print (b[i][j], end = "")
    print ()
