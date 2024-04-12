import sys
N = 64

dp = [0] * N
div = [[-1, -1] for _ in range (N)]
for i in range (2, N) :
  for p1 in range (1, i) :
    if dp[i] : break
    p2 = i - p1
    if not dp[p1] and not dp[p2] :
      dp[i] = 1
      div[i] = (p1, p2)
      break

def get_cnt_of_one (n) :
  cnt = 0
  while n :
    if n & 1 : cnt += 1
    n >>= 1
  return cnt

def send (l) :
  for i in range (len (l)) :
    print (l[i], end = ' ' if i < len (l) - 1 else '\n')
  sys.stdout.flush ()
  if l[0] != 'first' : return input ()

def div_n_2_p1_p2 (n) :
  # dp[get_cnt_of_one (n)] should be '1'
  p1, p2 = 0, 0
  cnt1, cnt2 = div[get_cnt_of_one (n)]
  for i in range (N) :
    if (n >> i) & 1 :
      if cnt2 > 0 :
        p2 += 1 << i
        cnt2 -= 1
      else :
        p1 += 1 << i
        cnt1 -= 1
  return p1, p2

for _ in range (int (input ())) :
  n = int (input ())
  cnt = get_cnt_of_one (n)
  if dp[cnt] :
    send (['first'])
    p1, p2 = div_n_2_p1_p2 (n)
    while True :
      rcv = list (map (int, send ([p1, p2]).split ()))
      if rcv[0] == 0 :
        break
      elif dp[get_cnt_of_one (rcv[0])] :
        n = rcv[0]
      else :
        n = rcv[1]
      p1, p2 = div_n_2_p1_p2 (n)
  else :
    rcv = list (map (int, send (['second']).split ()))
    while True :
      if rcv[0] == 0 :
        break
      elif dp[get_cnt_of_one (rcv[0])] :
        n = rcv[0]
      else :
        n = rcv[1]
      p1, p2 = div_n_2_p1_p2 (n)
      rcv = list (map (int, send ([p1, p2]).split ()))