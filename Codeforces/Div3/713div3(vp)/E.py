import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n, l, r ,s = map (int, input ().split ())
  len = r - l + 1
  def cal (l, r) -> int : return (r - l + 1) * (r + l) // 2
  if cal (n - len + 1, n) < s  or cal (1, len) > s: print (-1); return
  cur = n; used = set (); ans = [0] * (n + 1)
  for i in range (l, r + 1) :
    while cur + cal (1, r - i) > s : cur -= 1
    s -= cur; ans[i] = cur; used.add (cur); cur -= 1
  cur = 1
  for i in range (1, n + 1) :
    while cur in used : cur += 1
    if ans[i] : continue
    ans[i] = cur; cur += 1
  for i in range (1, n + 1) : print (ans[i], end = ' ')
  print ()
  
for t in range (int (input ())) : charming ()
