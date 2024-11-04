h = int(input())
ans = 0
while h >= 0:
  h -= (1 << ans)
  ans += 1
print(ans)