n, k, m = map (int, input ().split ())
words = list (map (str, input ().split ()))
a = list (map (int, input ().split ()))
group, val = list (), list ()
bel = dict ()
for i in range (k) :
  group.append (list (map (int, input ().split ())))
  mn = 10 ** 9
  for j in range (1, group[-1][0] + 1) :
    group[i][j] -= 1
    mn = min (mn, a[group[-1][j]])
    bel[words[group[-1][j]]] = i
  val.append (mn)
send = list (map (str, input ().split ()))
#print (bel, send)
ans = 0
for s in send : ans += val[bel[s]]
print (ans)
