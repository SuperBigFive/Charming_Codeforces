n = int (input ())
cost = [[] for i in range (10)]
cnt = [0] * 10
for i in range (n) :
  a, b = map (int, input ().split ())
  cost[a].append (b)
  cnt[a] += 1
ans = 0
for i in range (10) :
  if cnt[i] == 0 : continue
  cost[i].sort ()
  if cnt[i] > n // 10 :
    delta = cnt[i] - n // 10
    for j in range (delta) :
      ans += cost[i][j]
print (ans)
    
