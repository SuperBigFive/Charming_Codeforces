n = int (input ())
if n == 1 : print (1, 0); exit (0)
factor = list ()
for i in range (2, n) :
  if i * i > n : break
  elif n % i == 0 :
    cnt = 0
    while n % i == 0 : cnt += 1; n //= i
    factor.append ((i, cnt))
if n > 1 : factor.append ((n, 1))
isPow2 = [-1] * 30
isPow2[1] = 0; isPow2[2] = 1; isPow2[4] = 2;
isPow2[8] = 3; isPow2[16] = 4
ok = (True if isPow2[factor[0][1]] >= 0 else False)
siz = len (factor); mn = 1; mx_cnt = 0
for i in range (siz) :
  if factor[i][1] != factor[0][1] : ok = False
  mn *= factor[i][0]
  mx_cnt = max (mx_cnt, factor[i][1])
if ok : print (mn, isPow2[factor[0][1]])
else :
  cnt = -1 if isPow2[mx_cnt] >= 0 else 0
  while mx_cnt > 0 : cnt += 1; mx_cnt //= 2
  print (mn, cnt + 1)
