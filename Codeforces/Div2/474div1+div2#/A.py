s = input (); n = len (s)
i, j = 0, 0
if s[0] != 'a' : print ("NO"); exit (0)
while j < n and s[j] == 'a' : j += 1
cnta = j - i; i = j
if j >= n : print ("NO"); exit (0)
if s[i] != 'b' : print ("NO"); exit (0)
while j < n and s[j] == 'b' : j += 1
cntb = j - i; i = j
if j >= n : print ("NO"); exit (0)
if s[i] != 'c' : print ("NO"); exit (0)
while j < n and s[j] == 'c' : j += 1
if j < n : print ("NO"); exit (0)
cntc = j - i
if cntc != cnta and cntc != cntb : print ("NO")
else : print ("YES")
