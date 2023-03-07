for t in range (int (input ())) :
  input ()
  n, k = map (int, input ().split ())
  pos = set (map (int, input ().split ()))
  adj = [set () for i in range (n + 1)]
  for i in range (n - 1) :
    u, v = map (int, input ().split ())
    adj[u].add (v)
    adj[v].add (u)
  player = set ([1])
  friends = set () | pos
  vis = set ()
  forb = set () | pos
  ok = False
  while 1 :
    if not player : break
    player_nxt = set ()
    for i in player :
      vis.add (i)
      if len (adj[i]) == 1 and i != 1 :
        ok = True
        break
      for j in adj[i] :
        if j not in vis and j not in forb :
          player_nxt.add (j)
    if ok == True : break
    friends_nxt = set ()
    for i in friends :
      for j in adj[i] :
        if j not in vis :
          vis.add (j)
          forb.add (j)
          friends_nxt.add (j)
    player = player_nxt - friends_nxt
    friends = friends_nxt
    if ok == True : break
  print ("YES" if ok == True else "NO")
