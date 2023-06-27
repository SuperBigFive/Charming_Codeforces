n = int (input ())
m = [0] + list (map (int, input ().split ())) + [0]
cnt = 0; ans = 0; mn = [0] * (n + 5)
for i in range (n, 0, -1) : mn[i] = max (m[i] + 1, m[i + 1], mn[i + 1] - 1)
for i in range (1, n + 1) :
  if cnt < mn[i] :
    ans += cnt - m[i]
    cnt += 1
  else :
    ans += cnt - m[i] - 1
print (ans)
