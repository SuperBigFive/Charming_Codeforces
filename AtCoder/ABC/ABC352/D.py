n, k = map (int, input ().split ())
p = list (map (lambda x : int (x) - 1, input ().split ()))
rev = [0] * n
for i in range (n) : rev[p[i]] = i
ans = n
stk_inc, stk_dec, stk = [], [], []
for i in range (k) :
  while len (stk_inc) > 0 and stk_inc[-1][0] > rev[i] :
    stk_inc.pop ()
  while len (stk_dec) > 0 and stk_dec[-1][0] < rev[i] :
    stk_dec.pop ()
  stk_inc.append ((rev[i], i))
  stk_dec.append ((rev[i], i))

l = 1; r = k
head_inc = 0; tail_inc = len (stk_inc) - 1
head_dec = 0; tail_dec = len (stk_dec) - 1
ans = abs (stk_dec[head_dec][0] - stk_inc[head_inc][0])
while r < n :
  if head_inc <= tail_inc and stk_inc[head_inc][1] < l :
    head_inc += 1
  if head_dec <= tail_dec and stk_dec[head_dec][1] < l :
    head_dec += 1
  while head_inc <= tail_inc and stk_inc[tail_inc][0] > rev[r] :
    stk_inc.pop (); tail_inc -= 1
  while head_dec <= tail_dec and stk_dec[tail_dec][0] < rev[r] :
    stk_dec.pop (); tail_dec -= 1
  stk_inc.append ((rev[r], r)); tail_inc += 1
  stk_dec.append ((rev[r], r)); tail_dec += 1
  ans = min (ans, abs (stk_dec[head_dec][0] - stk_inc[head_inc][0]))
  l += 1; r += 1

print (ans)