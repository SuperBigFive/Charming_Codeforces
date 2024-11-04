n = int (input ())
a = list (map (int, input ().split ()))
pos = list (list () for i in range (n + 1))
for i in range (n * 3) : pos[a[i]].append (i + 1)
ans = list ([0, 0] for i in range (n))
for i in range (1, n + 1) : ans[i - 1] = [i, pos[i][1]]
ans.sort (key = lambda x : x[1])
for i, cnt in ans : print (i, end = " ")
