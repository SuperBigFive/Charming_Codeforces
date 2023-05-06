for t in range (int (input ())) :
  n, m, k = map (int, input ().split ())
  if n == 1 : print (1); continue
  tmp_n = n; ok = dict ()
  while tmp_n : ok[tmp_n] = 1; tmp_n = (tmp_n + (m - 2)) // m
  tree_layer = 1; cur = m * m
  while (cur - 1) // (m - 1) < n : tree_layer += 1; cur *= m
  tree_layer += 1
  k_layer = 1; cur = m
  while (cur - 1) // (m - 1) < k :  k_layer += 1; cur *= m
  r_most = k; delta = tree_layer - k_layer + 1
  if ok.get (k, 0) :
    for i in range (delta - 1) :
      if r_most < n : r_most = r_most * m + 1
    sum_complete = (m ** delta - 1) // (m - 1)
    #print (tree_layer, k_layer, r_most, sum_complete)
    print (sum_complete - (r_most - n))
  else :
    for i in range (delta - 1) :
      r_most = r_most * m + 1
    if r_most <= n :
      sum_complete = (m ** (delta - 0) // (m - 1))
      print (sum_complete)
    else :
      sum_complete = (m ** (delta - 1)) // (m - 1)
      print (sum_complete)
  
  
