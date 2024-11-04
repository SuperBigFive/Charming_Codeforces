MOD = 998244353

n = int (input ())
p = list (map (lambda x : int (x) - 1, input ().split ()))
s = input ()

ans = 0
# 0 - 0, 1 - 1, 2 - 2 ... n - 1 - n - 1
# 0 - 1, 1 - 2, 2 - 3 ... n - 1 - 0
taken1, taken2 = [0] * n, [0] * n
cnt1, ok1, cnt2, ok2 = 0, True, 0, True
for idx in p :
  l_fork_idx = idx
  r_fork_idx = (idx + 1) % n
  if ok1 :
    if taken1[l_fork_idx] : ok1 = False
    elif s[idx] == 'L' :
      taken1[l_fork_idx] = 1
    elif s[idx] == 'R' :
      if not taken1[r_fork_idx] : ok1 = False
      else : taken1[l_fork_idx] = 1
    else :
      if taken1[r_fork_idx] : cnt1 += 1
      taken1[l_fork_idx] = 1
  if ok2 :
    if taken2[r_fork_idx] : ok2 = False
    elif s[idx] == 'R' :
      taken2[r_fork_idx] = 1
    elif s[idx] == 'L' :
      if not taken2[l_fork_idx] : ok2 = False
      else : taken2[r_fork_idx] = 1
    else :
      if taken2[l_fork_idx] : cnt2 += 1
      taken2[r_fork_idx] = 1
ans = (ok1 * pow (2, cnt1, MOD) % MOD + ok2 * pow (2, cnt2, MOD)) % MOD
print (ans)
