n = int (input ())
a = [0] + list (map (int, input ().split ()))
pre = [0] * (n + 5); power = 1; cost = 0; pre[0] = 1
for i in range (1, n + 1) :
  if power < a[i] :
    ncost = (a[i] - power + pre[i - 1] - 1) // pre[i - 1]
    cost += ncost
    power += ncost * pre[i - 1]
  power += a[i]
  pre[i] = pre[i - 1] + a[i]
print (cost)
