MOD = 10 ** 9 + 7
inv = dict ()

def QSM (x, p) -> int :
    ans = 1
    while p :
        if p & 1 : ans = (ans * x) % MOD
        p >>= 1; x = (x * x) % MOD
    return ans

def getInv (x) -> int :
    if x in inv : return inv[x]
    else : inv[x] = QSM (x, MOD - 2); return inv[x]

n, m = map (int, input ().split ())
pg = 0; pe = 1
a = list (map (int, input ().split ()))
b = list (map (int, input ().split ()))
c = getInv (m); d = (m - 1) * getInv (2 * m) % MOD
for i in range (n) :
    if a[i] == 0 and b[i] == 0 :
        pg = (pg + pe * d) % MOD
        pe = (pe * c) % MOD
    elif a[i] == 0 :
        pg = (pg + ((pe * c) % MOD) * (m - b[i])) % MOD
        pe = (pe * c) % MOD
    elif b[i] == 0 :
        pg = (pg + ((pe * c) % MOD) * (a[i] - 1)) % MOD
        pe = (pe * c) % MOD
    else :
        if a[i] == b[i] : continue
        elif a[i] > b[i] : pg = (pg + pe) % MOD; pe = 0
        else : pe = 0
pg = ((pg % MOD) + MOD) % MOD
print (pg)
