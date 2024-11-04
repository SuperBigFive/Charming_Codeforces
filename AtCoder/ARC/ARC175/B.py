n, a, b = map (int, input ().split ())
s = input ()
cnt_right, cnt_left = 0, 0
for ch in s :
  if ch == '(' : cnt_left += 1
  else :
    if cnt_left > 0 : cnt_left -= 1
    else : cnt_right += 1
if cnt_right < cnt_left : 
  cnt_right, cnt_left = cnt_left, cnt_right
mid = (cnt_right + cnt_left) // 2
delta = cnt_right - mid
ans = delta * b
if cnt_left :
  nans = ((cnt_left + 1) // 2) * a
  nans = min (nans, (cnt_left - (cnt_left & 1)) * b + (cnt_left & 1) * 2 * b)
  nans = min (nans, cnt_left // 2 * a + 2 * b)
  nans = min (nans, (cnt_left - (cnt_left & 1)) * b + a)
  ans += nans
print (ans)
