repunit = []
for i in range (12) :
    a = 1
    for j in range (i) :
        a = a * 10 + 1
    repunit.append (a)
n = len (repunit)
s = []
for i in range (n) :
    for j in range (n) :
        for k in range (n) :
            s.append (repunit[i] + repunit[j] + repunit[k])
s = list (set (s))
s.sort ()

n = int (input ())
print (s[n - 1])