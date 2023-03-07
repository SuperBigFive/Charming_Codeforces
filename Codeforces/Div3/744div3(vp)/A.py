import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  s = input ()
  cnt = {'A' : 0, 'B' : 0, 'C' : 0}
  for ch in s : cnt[ch] += 1
  if cnt['B'] == cnt['A'] + cnt['C'] : print ("YES")
  else : print ("NO")

for t in range (int (input ())) : charming ()
