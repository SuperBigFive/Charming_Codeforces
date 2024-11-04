for _ in range(int(input())):
  n = int(input())
  p = [0] + list(map(int, input().split()))
  mn = n + 1; mx = 0
  for i in range(1, n + 1) :
    if p[i] != i :
      mx = max(mx, p[i], p[p[i]])
      mn = min(mn, p[i], p[p[i]])
  ans = 0
  for l in range(1, n + 2):
    ans += (2 * n - max(l + 1, (mx + 1)) + 1)
  for l in range(n + 2, 2 * n + 1):
    if l - n > mn : break
    else :
      ans += (2 * n - (l + 1) + 1)
  
  s = set()
  for i in range(1, n + 1):
    if p[i] != i : s.add(abs(p[i] + p[p[i]])) 
  if len(s) == 1 : ans += 1
  elif len(s) == 0 : ans += n * 2

  print(ans)
