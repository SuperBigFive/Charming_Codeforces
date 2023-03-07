nt (2e6 + 5); M = int (4e3 + 50); mod = 998244353
prim = list (); vis = [0] * (N)
fac = [0] * (M); inv = [0] * (M)

def qsm (num, p) :
    res = 1
    while p :
        if p & 1: res = (res * num) % mod
        p //= 2; num = (num * num) % mod
    return res

for i in range (2, N) :
    if vis[i] == 0 : prim.append (i)
    for j in range (len (prim)) :
        if i * prim[j] >= N : break
        vis[i * prim[j]] = True
        if i % prim[j] == 0 : break

fac[0] = inv[0] = vis[1] = 1
for i in range (1, M) :
    fac[i] = (fac[i - 1] * i) % mod
    inv[i] = qsm (fac[i], mod - 2)

n = int (input ())
a = list (map (int, input ().split ()))
cnt = dict ()

for i in a : 
    if i in cnt : cnt[i] += 1
    else : cnt[i] = 1
b = list (); ans = fac[n]
for i in cnt.keys () :
    if vis[i] : ans = (ans * inv[cnt[i]]) % mod
    else : b.append ((i, cnt[i]))
m = len (b)
if m < n : print (0); exit (0)
f = list ([0] * (M) for i in range (M))
f[0][1] = inv[b[0][1] - 1]
f[0][0] = inv[b[0][1]]
for i in range (1, m) :
    f[i][0] = (f[i - 1][0] * inv[b[i][1]]) % mod
    for j in range (1, min (i + 2, n + 1)) :
        f[i][j] = (f[i - 1][j] * inv[b[i][1]] + f[i - 1][j - 1] \
                * inv[b[i][1] - 1]) % mod
ans = ans * f[m - 1][n]
ans = ((ans % mod) + mod) % mod 
print (ans)
