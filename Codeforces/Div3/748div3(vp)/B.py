import sys
N = int (2e5 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = input (); mn = N; length = len (n)
  ok1 = False; ok2 = False
  for i in list (reversed (range (length))) :
    if ok1 == False and n[i] == "5" : ok1 = True
    elif ok1 == True and ok2 == False and (n[i] == "2" or n[i] == "7") :
      mn = min (mn, length - i - 2)
      ok2 = True
      break
  ok1 = False; ok2 = False
  for i in list (reversed (range (length))) :
    if ok1 == False and n[i] == "0" : ok1 = True
    elif ok1 == True and ok2 == False and (n[i] == "5" or n[i] == "0") :
      mn = min (mn, length - i - 2)
      ok2 = True
      break
  print (mn)
  
for t in range (int (input ())) : charming ()
