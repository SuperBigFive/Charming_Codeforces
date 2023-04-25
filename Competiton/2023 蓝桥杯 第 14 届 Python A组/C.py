n = int (input ())
event = []
ans = -1
A = list (map (int, input ().split ()))
B = list (map (int, input ().split ()))
C = list (map (int, input ().split ()))

for i in range (n) :
  a, b, c = A[i], B[i], C[i]
  event.append ((a, b, c))

def solve (a) :
  global n
  more = 0; nans = 0
  #print (a)
  for i in range (n) :
    if more + (a[i][0] - a[i][1] - a[i][2]) <= 0 : break
    else : more += (a[i][0] - a[i][1] - a[i][2]); nans += 1
  if nans == 0 : return -1
  else : return nans
  
nevent = [0] * n
for i in range (3) :
  for j in range (n) :
    nevent[j] = (event[j][i % 3], event[j][(i + 1) % 3],
                    event[j][(i + 2) % 3])
  nevent.sort (key = lambda x : -(x[0] - x[1] - x[2]))
  ans = max (ans, solve (nevent))
print (ans)
