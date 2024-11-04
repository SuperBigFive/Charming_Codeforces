n, q = map (int, input ().split ())
card = list ([0, 0] for i in range (1, n + 5))
for i in range (q) :
  c, x = map (int, input ().split ())
  if c == 1 : card[x][0] += 1
  elif c == 2 : card[x][1] += 1
  else : print ("Yes" if card[x][0] >= 2 or card[x][1] >= 1 else "No")
