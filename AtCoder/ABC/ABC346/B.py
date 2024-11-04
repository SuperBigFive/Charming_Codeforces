w, b = map (int, input ().split ())
s = 'wbwbwwbwbwbw'
ss = str ()
for i in range (100) :
  ss += s
n = len (ss)
ok = False
for i in range (n - (w + b)) :
  cs = ss[i : i + (w + b)]
  cntw, cntb = 0, 0
  for ch in cs :
    if ch == 'w' : cntw += 1
    else : cntb += 1
  if cntw == w and cntb == b :
    ok = True
    print ('Yes')
    break
if not ok :
  print ('No')