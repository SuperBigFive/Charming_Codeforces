import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  a, b ,k = map (int, input ().split ())
  arr1 = list (map (int, input ().split ()))
  arr2 = list (map (int, input ().split ()))
  pair = list (zip (arr1, arr2))
  cnt_boy = [0] * (a + 1); cnt_girl = [0] * (b + 1)
  d = dict ()
  for i, j in pair :
    if (i, j) not in d : d[(i, j)] = 1
    else : d[(i, j)] += 1
    cnt_boy[i] += 1; cnt_girl[j] += 1
  res = 0;
  for i, j in pair :
    res += k - cnt_boy[i] - cnt_girl[j]
    if (i, j) in d : res += d[(i, j)]
  print (res // 2)
  
for t in range (int (input ())) : charming ()
