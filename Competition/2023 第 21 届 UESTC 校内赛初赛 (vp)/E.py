n, k = map (int, input ().split ())
cnt = dict (); query = []; last = -1
for i in range (n) :
  a, b = map (int, input ().split ())
  if a == last : query[-1][1] += b
  else : query.append ([a, b])
  last = a
for a, b in query :
  if b <= k : cnt[a] = cnt.get (a, 0) + b
  else :
    d = (b - 1) // k
    cnt[a] = cnt.get (a, 0) + 2 * k * d + (b % k if b % k else k)
keys = list (cnt.keys ())
keys.sort ()
print (len (keys))
for i in keys :
  print (i, cnt[i])
