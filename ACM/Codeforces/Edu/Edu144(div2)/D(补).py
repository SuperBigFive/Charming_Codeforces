import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

for t in range (int (input ())) :
  n, k, x = map (int, input ().split ())
  a = [0] + list (map (int, input ().split ()))
  pre = [0] * (n + 5); suf_mx = [0] * (n + 5)
  for i in range (1, n + 1) : a[i] -= x; pre[i] = pre[i - 1] + a[i]
  suf_mx[n] = pre[n]
  for i in range (n - 1, 0, -1) : suf_mx[i] = max (suf_mx[i + 1], pre[i])
  res = 0; remain = 0
  if k == 0 :
    for i in range (1, n + 1) : res = max (res, suf_mx[i] - pre[i - 1])
  elif k == n :
    for i in range (1, n + 1) :
      a[i] += 2 * x; remain = max (0, remain + a[i])
      res = max (res, remain)
  elif x >= 0 :
    for i in range (1, n + 1) :
      remain = 0
      for j in range (i, min (n + 1, i + k)) :
        remain += a[j] + 2 * x
        res = max (res, remain)
      if i + k > n : continue
      res = max (res, remain + suf_mx[i + k] - pre[i + k - 1])
  else :
    stk = [0] * (n + 5); stk_id = [0] * (n + 5); head = 1; tail = 0; p = 1;
    for i in range (1, k + 2) :
      while p <= i + n - k - 1:
        while head <= tail and p > stk_id[head] + n - k - 1 : head += 1
        while head <= tail and stk[tail] <= pre[p] : tail -= 1
        tail += 1
        stk[tail] = pre[p]; stk_id[tail] = p; p += 1
      res = max (res, stk[head] - pre[i - 1])
      remain = pre[i + n - k - 1] - pre[i - 1]
      for j in range (i + n - k, n + 1) :
        remain += a[j] + 2 * x
        res = max (res, remain)
    for i in range (k + 2, n + 1) : res = max (res, suf_mx[i] - pre[i - 1])
  print (res)
