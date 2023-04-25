for t in range (int (input ())) :
  n, m = map (int, input ().split ())
  Line = []
  for i in range (n) :
    k = int (input ())
    Line.append (k)
  Line.sort ()

  def check (b, k, a, c) -> bool : return (b - k) * (b - k) < 4 * a * c
  
  for i in range (1, m + 1) :
    a, b ,c = map (int, input ().split ())
    if c <= 0 : print ("NO"); continue
    l = 0; r = n - 1; ans = 0
    while l <= r :
      mid = (l + r) // 2
      if Line[mid] < b : l = mid + 1; ans = mid
      else : r = mid - 1
    if check (b, Line[ans], a, c) : print ("YES"); print (Line[ans])
    elif ans + 1 < n and check (b, Line[ans + 1], a, c) : print ("YES"); print (Line[ans + 1])
    else : print ("NO")
    
