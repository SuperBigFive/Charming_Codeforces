MOD = 10 ** 9 + 7
for t in range (int (input ())) :
  n = int (input ()); ans = 1; dec = 0
  while n :
    if n & 1 : ans = (ans * 3) % MOD; dec = (dec * 2 + 3) % MOD
    n //= 2
  ans = ((ans - dec) % MOD + MOD) % MOD
  print (ans)
  
