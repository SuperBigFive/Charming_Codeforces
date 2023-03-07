for t in range (int (input ())) :
  n, k = map (int, input ().split ())
  s = input (); cnt = dict ()
  low_ch = "abcdefghijklmnopqrstuvwxyz"
  up_ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  for i in low_ch : cnt[i] = 0
  for i in up_ch : cnt[i] = 0
  for i in s : cnt[i] += 1
  res = 0
  for i in range (len (low_ch)) :
    res += min (cnt[low_ch[i]], cnt[up_ch[i]])
    diff = abs (cnt[low_ch[i]] - cnt[up_ch[i]]) // 2
    res += min (diff, k); k -= min (k, diff)
  print (res)
