N = 10 **5 + 5; MOD = 10 ** 9 + 7
POW2 = [1] * N; POW10 = [1] * N
for i in range (1, N) : 
    POW2[i] = (POW2[i - 1] * 2) % MOD
    POW10[i] = (POW10[i - 1] * 10) % MOD
pre1 = [1] * N; pre2 = [0] * N
for i in range (1, N): 
    pre1[i] = (pre1[i - 1] + (i + 1) * POW10[i]) % MOD
    pre2[i] = pre2[i - 1] + i
n = input (); m = len (n); ans = 0; pre1[-1] = 0
for i in range (m) :
    ans = (ans + (ord (n[i]) - ord ('0')) * \
           (pre1[m - i - 2] + (pre2[i] + 1) * POW10[m - i - 1])) % MOD
    ans = (ans - (ord (n[i]) - ord ('0')) * POW10[m - i - 1]) % MOD
ans = ((ans % MOD) + MOD) % MOD
print (ans)
