MOD = 998244353
n, m, a, b = map (int, input ().split ())
mp = [[] for i in range (n + 5)]
mx = [[-1 for i in range (n + 5)] for j in range (m + 5)]
mn = [[10 ** 9 + 5 for i in range (n + 5)] for j in range (m + 5)]
for i in range (1, n + 1) :
  mp[i] = [0] + list (map (int, input ().split ()))
  stk_val_mx = [0] * (m + 5); stk_id_mx = [0] * (m + 5); head_mx = 1; tail_mx = 0
  stk_val_mn = [0] * (m + 5); stk_id_mn = [0] * (m + 5); head_mn = 1; tail_mn = 0
  for j in range (1, m + 1) :
    while head_mx <= tail_mx and stk_id_mx[head_mx] + b - 1 < j : head_mx += 1
    while head_mx <= tail_mx and stk_val_mx[tail_mx] <= mp[i][j] : tail_mx -= 1
    tail_mx += 1; stk_val_mx[tail_mx] = mp[i][j]; stk_id_mx[tail_mx] = j

    while head_mn <= tail_mn and stk_id_mn[head_mn] + b - 1 < j : head_mn += 1
    while head_mn <= tail_mn and stk_val_mn[tail_mn] >= mp[i][j] : tail_mn -= 1
    tail_mn += 1; stk_val_mn[tail_mn] = mp[i][j]; stk_id_mn[tail_mn] = j
    
    if j >= b :
      for k in range (max (1, i - a + 1), i + 1) :
        #print (stk_val_mx[head_mx], stk_val_mn[head_mn])
        #if k == 1 and j - b + 1 == 2 : print (i, j, stk_val_mx, head_mx)
        mx[k][j - b + 1] = max (mx[k][j - b + 1], stk_val_mx[head_mx])
        mn[k][j - b + 1] = min (mn[k][j - b + 1], stk_val_mn[head_mn])

ans = 0
for i in range (1, n - a + 2) :
  for j in range (1, m - b + 2) :
    ans = (ans + mx[i][j] * mn[i][j]) % MOD
   # print (i, j, ans, mx[i][j], mn[i][j])
print (ans)

'''nans = 0
for i in range (1, n - a + 2) :
  for j in range (1, m - b + 2) :
    MX = -1; MN = 10 ** 9 + 5
    for p in range (i, i + a) :
      for q in range (j, j + b) :
        MX = max (MX, mp[p][q])
        MN = min (MN, mp[p][q])
    nans += MX * MN
    print (i, j, nans, MX, MN);
print (nans)'''
