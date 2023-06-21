for t in range (int (input ())) :
  n, m = map (int, input ().split ())
  x = [0] * n; seg = list ()
  for i in range (m) :
    seg.append (list (map (int, input ().split ())))
  q = int (input ())
  seq = list ()
  for i in range (q) : seq.append (int (input ()) - 1)
  l, r, ans = 0, q, -1
  pre = [0] * n; haveAns = 0
  while l <= r :
    mid = (l + r) // 2
    for i in range (mid) : x[seq[i]] = 1
    for i in range (n) :
      if i == 0 : pre[i] = x[i]
      else : pre[i] = pre[i - 1] + x[i]
    #print (mid, pre)
    ok = False
    for ql, qr in seg :
      ql -= 1; qr -= 1
      if (pre[qr] - pre[ql] + x[ql]) * 2 > qr - ql + 1 : ok = True
    if not ok : l = mid + 1
    else : r = mid - 1; ans = mid
    for i in range (mid) : x[seq[i]] = 0
  print (ans)
