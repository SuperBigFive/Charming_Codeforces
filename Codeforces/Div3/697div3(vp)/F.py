import sys
N = int (1e3 + 5)
sys.setrecursionlimit (N)

def charming () :
  n = int (input ())
  mat1 = list ([] for i in range (n + 1))
  mat2 = list ([] for i in range (n + 1))
  mat3 = list ([0] * (n + 1) for i in range (n + 1))
  for i in range (1, n + 1) :
    mat1[i] = [0]
    s = input ()
    for j in range (n) : mat1[i].append (int (s[j]))
  input ()
  for i in range (1, n + 1) :
    mat2[i] = [0]
    s = input ()
    for j in range (n) : mat2[i].append (int (s[j]))
  for i in range (1, n + 1) :
    for j in range (1, n + 1) :
      mat3[i][j] = mat1[i][j] ^ mat2[i][j]
  for i in range (2, n + 1) :
    for j in range (1, n + 1) :
      if mat3[1][1] ^ mat3[i][1] != mat3[1][j] ^ mat3[i][j] :
        print ("NO"); return
  print ("YES")

for t in range (int (input ())) : charming ()
