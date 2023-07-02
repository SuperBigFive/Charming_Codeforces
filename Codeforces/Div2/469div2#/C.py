s = input (); n = len (s); m = 0
ans = list (); lastWith0 = list (); lastWith1 = list ()
siz, len0, len1 = 0, 0, 0
for i in range (n) :
    if s[i] == '0' :
        if len1 == 0 :
            ans.append ([i])
            lastWith0.append (siz)
            len0 += 1; siz += 1
        else :
            ans[lastWith1[-1]].append (i)
            lastWith0.append (lastWith1[-1])
            len0 += 1
            lastWith1.pop ()
            len1 -= 1
    else :
        if len0 == 0 : print (-1); exit (0)
        else :
            ans[lastWith0[-1]].append (i)
            lastWith1.append (lastWith0[-1])
            len1 += 1
            lastWith0.pop ()
            len0 -= 1
if len1 > 0 : print (-1); exit (0)
print (siz)
for i in range (siz) :
    print (len (ans[i]), end = " ")
    for j in ans[i] :
        print (j + 1, end = " ")
    print ()
            
        
