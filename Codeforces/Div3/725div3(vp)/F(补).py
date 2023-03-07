import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  l, r = map (int, input ().split ())
  ans = [0] * 10; remain = 0
  for i in range (10) :
    remain = remain * 10 + 1
    ans[i] = remain
    
  def cal (num) -> int :
    cnt = 0; res = 0
    while num :
      res += (num % 10) * ans[cnt]
      num //= 10
      cnt += 1
    return res
  
  print (cal (r) - cal (l))

for t in range (int (input ())) : charming ()
