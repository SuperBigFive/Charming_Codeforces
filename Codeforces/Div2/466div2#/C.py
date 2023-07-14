n, k = map (int, input ().split ())
s = input ()
ok = [0] * 26
for ch in s : ch2num = ord (ch) - ord ('a'); ok[ch2num] = 1
mx = -1; mn = -1
for i in range (25, -1, -1) :
    if ok[i] :
        if mx == -1 : mx = i
        mn = i
if k > n :
    t = s
    for i in range (k - n) : t += chr (ord ('a') + mn)
    print (t)
    exit (0)
t = str ()
for i in range (k - 1, -1, -1) :
    ch2num = ord (s[i]) - ord ('a')
    if ch2num < mx :
        nxt = ch2num + 1
        while nxt < 26 and not ok[nxt] : nxt += 1
        t = s[:i] + chr (ord ('a') + nxt)
        for i in range (i + 1, k) : t += chr (ord ('a') + mn)
        print (t)
        break
