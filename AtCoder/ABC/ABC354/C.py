n = int(input())
cards = [[i] + list(map(int, input().split())) for i in range(n)]
cards.sort(key=lambda x : x[1])
stk = []
for i in range(n):
  while len(stk) > 0 and cards[stk[-1]][2] > cards[i][2] : stk.pop()
  stk.append(i)

m = len(stk)
ans = [cards[stk[i]][0] + 1 for i in range(m)]
ans.sort()

print(m)
for i in range(m):
  print(ans[i], end = ' ' if i < m - 1 else '\n')