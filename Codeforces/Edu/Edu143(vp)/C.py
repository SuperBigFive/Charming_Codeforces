import sys
N = int (2e5 + 5)
#sys.setrecursionlimit (N)

for t in range (int (input ())) :
  n = int (input ())
  a = [0] + list (map (int, input ().split ()))
  b = [0] + list (map (int, input ().split ()))
  ans = [0] * (n + 5); pre = [0] * (n + 5); tag = [0] * (n + 5)
  for i in range (1, n + 1) : pre[i] = pre[i - 1] + b[i]
  for i in range (1, n + 1) :
    l = i; r = n; k = i - 1
    while l <= r :
      mid = (l + r) // 2
      if pre[mid] - pre[i - 1] >= a[i] : r = mid - 1
      else : l = mid + 1; k = mid
    tag[i] += 1; tag[k + 1] -= 1; ans[k + 1] += a[i] - pre[k] + pre[i - 1];
  remain = 0
  for i in range (1, n + 1) :
    remain += tag[i]
    ans[i] += remain * b[i]
    print (ans[i], end = " ")
  print ()
