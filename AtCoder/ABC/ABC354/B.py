n = int(input())
p = []
t = 0
for i in range(n):
  p.append(input().split())
  t += int(p[-1][1])
p.sort(key=lambda x : x[0])
print(p[t % n][0])