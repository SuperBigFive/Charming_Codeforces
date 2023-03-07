import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); s = list ()
  cnt = list ([0] * 6 for i in range (n))
  for i in range (n) :
    s.append (input ())
    for ch in s[i] : cnt[i][ord (ch) - ord ('a') + 1] += 1
    cnt[i][0] = len (s[i])
  res = 0
  for i in range (1, 6) :
    cnt.sort (key = lambda x : 2 * x[i] - x[0], reverse = True)
    sum = 0; j = 0
    while j < n :
      sum += 2 * cnt[j][i] - cnt[j][0];
      if sum <= 0: break
      j += 1
    res = max (res, j)
  print (res)
  
for t in range (int (input ())) : charming ()
