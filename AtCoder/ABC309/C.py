n, k = map (int, input ().split ())
med = list ()
for i in range (n) : med.append (list (map (int, input ().split ())))
med.sort (key = lambda x : x[0], reverse = True)
p, q = 0, 0; suf = 0; ans = med[0][0] + 1
while p < n and suf <= k :
    q = p; suf += med[p][1]
    while q + 1 < n and med[q + 1][0] == med[p][0] : q += 1; suf += med[q][1]
    if suf <= k : ans = med[p][0]
    else : ans = med[p][0] + 1; break
    p = q + 1
    #print (suf, ans)
if suf <= k : ans = 1
print (ans)
