X, d = map (int, input ().split ())
ans = list (); cur = 1; cnt = 0
while X :
  if X & 1 :
    for i in range (cnt) : ans.append (cur)
    cur += d + 1
    ans.append (cur)
    cur += d + 1
  X //= 2; cnt += 1; cur += d + 1

print (len (ans))
for i in ans : print (i, end = " ")

    
