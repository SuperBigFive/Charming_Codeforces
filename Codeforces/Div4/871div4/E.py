N = 10 ** 3 + 5
dx = [0, 0, 1, -1]; dy = [1, -1, 0, 0]
vis = list ([0] * N for i in range (N))
a = list ()

def BFS (x, y) -> int :
    q = list (); q.append ((x, y))
    head = tail = 0; vis[x][y] = 1; ans = a[x][y]
    while head <= tail :
        cx, cy = q[head]; head += 1
        for i in range (4) :
            nx = cx + dx[i]; ny = cy + dy[i]
            if nx >= 1 and nx <= n and ny >= 1 and ny <= m \
               and vis[nx][ny] == 0 and a[nx][ny] > 0 :
                tail += 1; q.append ((nx,ny))
                vis[nx][ny] = 1; ans += a[nx][ny]
    return ans

for t in range (int (input ())) :
    n, m = map (int, input ().split ())
    for i in range (1, n + 1) :
        for j in range (1, m + 1) : vis[i][j] = 0
    a = list (); a.append ([0]); ans = 0
    for i in range (n) :
        a.append ([0] + list (map (int, input ().split ())))
    for i in range (1, n + 1) :
        for j in range (1, m + 1) :
            if vis[i][j] == 0 and a[i][j] > 0 : 
                ans = max (ans, BFS (i, j))
    print (ans)
