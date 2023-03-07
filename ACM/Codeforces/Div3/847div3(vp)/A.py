import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  pi = str (314159265358979323846264338327);
  ans = 0; s = input ()
  while ans < len (s) and s[ans] == pi[ans] : ans += 1
  print (ans)

for t in range (int (input ())) : charming ()
