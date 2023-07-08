import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ()); d = dict ()

  def get (s) :
    res = 0
    for i in range (len (s) - 3) :
      if "haha" in s[i : i + 4] : res += 1
    return res
  
  for i in range (n) :
    s = input ().replace ('=', ' '); flag = 0
    if s .find (':') != -1 : s = s.replace (':', ' ')
    else : s = s.replace ('+', ' '); flag = 1
    s = list (map (str, s.split ()))
    if flag == 0 :
      d[s[0]] = list (); d[s[0]].append (get (s[1]))
      d[s[0]] += [s[1][0 : min (len (s[1]), 3)],\
                  s[1][max (0, len (s[1]) - 3) : len (s[1])]]
    else :
      if s[0] not in d : d[s[0]] = [0, "", ""]
      ns = d[s[1]][2] + d[s[2]][1]
      d[s[0]][0] = d[s[1]][0] + d[s[2]][0] + get (ns)
      if len (d[s[1]][1]) < 3 :
        delta = 3 - len (d[s[1]][1])
        d[s[0]][1] = d[s[1]][1] + d[s[2]][1][0 : min (len (d[s[2]][1]), delta)]
      else : d[s[0]][1] = d[s[1]][1]
      if len (d[s[2]][2]) < 3:
        delta = 3 - len (d[s[2]][2])
        d[s[0]][2] = d[s[1]][2][max (0, len (d[s[1]][2]) - delta) : ] + d[s[2]][2]
      else : d[s[0]][2] = d[s[2]][2]
    if i == n - 1 : print (d[s[0]][0])
  
for t in range (int (input ())) : charming ()
