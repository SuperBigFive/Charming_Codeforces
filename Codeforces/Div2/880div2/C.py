def Calc (num) -> int :
  ans = 0
  while num : num //= 10; ans += 1
  return ans

for t in range (int (input ())) :
  A, B, C, k = map (int, input ().split ())
  if C > max (A, B)+ 1 or C < max (A, B) : print (-1); continue
  a = 1; b = 1; mxa = 1; mnb = 1; mnc = 1
  for i in range (A - 1) : a *= 10
  for i in range (B - 1) : b *= 10
  for i in range (C - 1) : mnc *= 10
  mxa = a * 10; mnb = b; mxb = b * 10 - 1
  while Calc (a + b) != C and b < mnb * 10 : b += 1
  if b >= mnb * 10 :
    b = mnb * 10 - 1
    while Calc (a + b) != C and a < mxa : a += 1
  #print (a, b)
  while Calc (a + mxb) > C : mxb -= 1
  while a < mxa and k > mxb - b + 1 :
    k -= mxb - b + 1; a += 1
    if mnb <= b - 1 : b -= 1
    while Calc (a + mxb) > C : mxb -= 1
  if a < mxa :
    b += k - 1
    print (str (a) + str (' + ') + str (b) + str (' = ') + str (a + b))
  else : print (-1)
    
    
