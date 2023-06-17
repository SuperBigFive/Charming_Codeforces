n, A, B, C, T = map (int, input ().split ())
t = list (map (int, input ().split ()))
ans = 0
for ti in t :
  if C > B : ans += (T - ti) * (C - B) + A
  else : ans += A
print (ans)
