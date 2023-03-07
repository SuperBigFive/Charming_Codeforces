for t in range (int (input ())) :
  n = int (input ()); voice = input ()
  p = 0; ok = True
  if voice[p] != 'm' and voice[p] != 'M' : print ("NO"); continue
  while p < n and (voice[p] == 'm' or voice[p] == 'M') : p += 1
  if p >= n or (voice[p] != 'e' and voice[p] != 'E') : print ("NO"); continue
  while p < n and (voice[p] == 'e' or voice[p] == 'E') : p += 1
  if p >= n or (voice[p] != 'o' and voice[p] != 'O') : print ("NO"); continue
  while p < n and (voice[p] == 'o'or voice[p] == 'O') : p += 1
  if p >= n or (voice[p] != 'w' and voice[p] != 'W') : print ("NO"); continue
  while p < n and (voice[p] == 'w' or voice[p] == 'W') : p += 1
  print ("YES" if p >= n else "NO")
    
