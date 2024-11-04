n, x, y, z = map (int, input ().split ())
if x <= z and z <= y :
  print ('Yes')
elif x >= z and z >= y :
  print ('Yes')
else :
  print ('No')