for _ in range(int(input())):
  n, m = map(int, input().split()); k = n + m + 1
  pro = list(map(int, input().split()))
  test = list(map(int, input().split()))
  skills = list(zip(pro, test))
  
  pre, pre0, pre1 = [0] * k, [0] * k, [0] * k
  for i in range(k):
    if i: pre[i] = pre[i - 1]; pre0[i] = pre0[i - 1]; pre1[i] = pre1[i - 1]
    if skills[i][0] > skills[i][1]:
      pre0[i] += 1
      pre[i] += skills[i][0]
    else:
      pre1[i] += 1
      pre[i] += skills[i][1]
  suf0, suf1 = [0] * k, [0] * k
  for i in range(k - 1, -1, -1):
    if i < k - 1: suf0[i] = suf0[i + 1]; suf1[i] = suf1[i + 1]
    suf0[i] += skills[i][0]
    suf1[i] += skills[i][1]

  cnt0, cnt1 = 0, 0
  sum = 0
  for i in range(k):
    if cnt0 >= n:
      print(sum + (suf1[i + 1] if i + 1 < k else 0), end = ' ' if i < k - 1 else '\n')
      sum += skills[i][1]
    elif cnt1 >= m:
      print(sum + (suf0[i + 1] if i + 1 < k else 0), end = ' ' if i < k - 1 else '\n')
      sum += skills[i][0]
    else:
      chk = (skills[i][0] > skills[i][1])
      d0 = n - cnt0; d1 = m - cnt1
      l = i + 1; r = k - 1; p = r
      while l <= r :
        mid = (l + r) // 2
        if pre0[mid] - chk >= n or pre1[mid] - (chk ^ 1) >= m:
          r = mid - 1; p = mid
        else: 
          l = mid + 1
      ans = pre[p] - max(skills[i][0], skills[i][1])
      if pre0[p] - chk >= n:
        ans += suf1[p + 1] if p + 1 < k else 0
      else:
        ans += suf0[p + 1] if p + 1 < k else 0
      print(ans, end = ' ' if i < k - 1 else '\n')
      if skills[i][0] > skills[i][1]:
        cnt0 += 1
        sum += skills[i][0]
      else:
        cnt1 += 1
        sum += skills[i][1]
