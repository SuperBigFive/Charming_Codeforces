s = input (); n = len (s)
cnt = 0
for i in s :
  if i == '1' : cnt += 1

cur_s = []
def dfs (u, lim) :
  global cnt
  if u > lim :
    ns = list ()
    for i in range (lim) : ns.append ('1' if cur_s[i] != cur_s[lim - i - 1] else '0')
    nans = ns.count ('1'); tmp_mx = 10 ** 9 + 5
    #print (ns)    
    for i in range (n) :
      nns = str ()
      for i in ns : nns = nns + str (i)
      print (nns)
      if nns == s[i : i + lim] :
        cur_mx = s[: i].count ('1') + s[i + lim :].count ('1')
        tmp_mx = min (tmp_mx, cur_mx)
        print (cur_mx)
      cnt = min (cnt, nans + tmp_mx)
    return
  
  cur_s.append ('0')
  dfs (u + 1, lim)
  cur_s.pop ()
  cur_s.append ('1')
  dfs (u + 1, lim)
  cur_s.pop ()
  
for i in range (1, n + 1) :
  dfs (1, i)

print (cnt)
