n = int (input ())
event = []
for i in range (n) :
    t, x = map (int, input ().split ())
    event.append ((t, x))
cnt = dict ()
for i in range (1, n + 1) :
    cnt[i] = 0

ans = []
for i in range (n - 1, -1, -1) :
    t, x = event[i]
    if t == 1 :
        if cnt[x] > 0 :
            cnt[x] -= 1
            ans.append (1)
        else :
            ans.append (0)
    else :
        cnt[x] += 1
chk = True
for i in range (1, n + 1) :
    if cnt[i] > 0 :
        chk = False
if chk == False :
    print (-1)
else :
    p = 0
    k = 0
    mx = 0
    ans.reverse ()
    for i in range (n) :
        t, x = event[i]
        if t == 1 :
            if ans[p] == 1 :
                k += 1
            p += 1
        else :
            k -= 1
        mx = max (mx, k)
    print (mx)
    for i in range (len (ans)) :
        print (ans[i], end = '\n' if i == len (ans) - 1 else ' ')