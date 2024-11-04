s = input (); t = input ()
p = 0; n = len (s); m = len (t)
ans = []
for i in range (m) :
  if p < n and s[p] == t[i] :
    ans.append (i + 1)
    p += 1
for i in range (n) :
  print (ans[i], end = ' ' if i < n - 1 else '\n')