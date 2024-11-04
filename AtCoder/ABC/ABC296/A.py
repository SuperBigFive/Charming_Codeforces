n = int (input ()); s = input (); ok = True
for i in range (n - 1) :
  if s[i] == s[i + 1] : ok = False
print ("Yes" if ok else "No")
