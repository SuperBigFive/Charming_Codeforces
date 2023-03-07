import sys
N = int (2e5 + 5)
LEN = 26
sys.setrecursionlimit (N)

def charming () :
  s = input (); cnt = [0] * LEN
  for ch in s : cnt[ord (ch) - ord ('a')] += 1
  res = 0; more = 0
  for i in cnt :
    if i > 1 : res += 1
    elif i == 1 : more += 1
  print (res + more // 2)

for t in range (int (input ())) : charming ()
