n, c = map (int, input ().split ())
a = [0] + list (map (int, input ().split ()))
if c <= 1 : print (0); exit (0)
dp = [0] * (n + 5); stk_val = [0] * (n + 5); stk_id = [0] * (n + 5)
head, tail = 1, 0
pre = [0] * (n + 5)
for i in range (1, n + 1) :
    pre[i] = pre[i - 1] + a[i]
    while head <= tail and stk_id[head] + c <= i : head += 1
    while head <= tail and stk_val[tail] >= a[i] : tail -= 1
    tail += 1; stk_id[tail] = i; stk_val[tail] = a[i]
    dp[i] = dp[i - 1] + a[i]
    if i >= c: dp[i] = min (dp[i], dp[i - c] + pre[i] - pre[i - c] - stk_val[head])
print (dp[n])
