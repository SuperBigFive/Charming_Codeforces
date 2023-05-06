'''n = int (input ())
fac = [1] * (15)
for i in range (2, 15) : fac[i] = fac[i - 1] * i
sum = 0
a = list (map (int, input ().split ()))
for i in a : sum += fac[i]
for i in range (14, -1, -1) :
  if sum % fac[i] == 0 : print (i); break'''
n = int (input ())
a = list (map (int, input ().split ()))
i = 0; cnt = dict ()
while i < n :
  j = i
  while j < n and a[j] == a[i] :
    cnt[a[i]] = cnt.get (a[i], 0) + 1; j += 1
  if cnt[a[i]] == a[i] + 1 :
    cnt[a[i] + 1] = cnt.get (a[i] + 1, 0) + 1
    if j >= n : print (a[i] + 1); break
    elif a[j] != a[i] + 1 : print (a[i] + 1); break
    else : i = j
  else : print (a[i]); break

