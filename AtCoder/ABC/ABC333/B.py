s, t = input (), input ()
a = abs (ord (s[0]) - ord (s[1]))
b = abs (ord (t[0]) - ord (t[1]))
if a > b :
    a, b = b, a
if a == b or a + b == 5 :
    print ("Yes")
else :
    print ("No")