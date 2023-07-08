n = int (input ())
a = list (map (int, input ().split ()))
cnt = dict ()
for i in a :
    if i > 0 : cnt[i] = cnt.get (i, 0) +  1
print (len (cnt.keys ()))
