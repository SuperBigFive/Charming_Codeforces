import copy

N = 26

cnt = [0] * N
s = input (); n = len (s)
ans, same = 0, 0
for i in range (n - 1, -1, -1) :
  ans += (n - 1 - i)
  ch2num = ord (s[i]) - ord ('a')
  ans -= cnt[ch2num]
  if cnt[ch2num] : same = 1
  cnt[ch2num] += 1
print (ans + same)
