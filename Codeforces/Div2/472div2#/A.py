n = int (input ()); s = input ()
i = 0; ok = False
while i < n:
  if s[i] != '?' :
    if i and s[i] == s[i - 1] : print ("No"); exit (0)
    i += 1; continue
  else :
    j = i
    while j + 1 < n and s[j + 1] == '?' : j += 1
    if i == 0 : ok = True
    elif j == n - 1 : ok = True
    elif j - i + 1 >= 2 or (s[i - 1] == s[j + 1]) : ok = True
    i = j + 1
print ("Yes" if ok else "No")
