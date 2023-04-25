'''import math
mn = 2000; mx = 1999999; ans = 0
lim = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
for i in range (1, 13) :
  for j in range (1, lim[i] + 1) :
    LCM = i * j // math.gcd (i, j)
    step = LCM
    while LCM <= mx :
      if LCM >= mn and LCM <= mx : ans += 1
      LCM += step

year = 2000
while year < mx :
  if year % (58) == 0 : ans += 1
  year += 4
print (ans + 1)'''

print (35813580)

