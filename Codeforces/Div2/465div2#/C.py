R, x1, y1, x2, y2 = map (int, input ().split ())
dis = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5
if dis >= R : print (x1, y1, R)
elif dis == 0 : print (x1 + R / 2, y1, R / 2)
else :
    x = (x1 + (x1 - x2) * R / dis + x2) / 2
    y = (y1 + (y1 - y2) * R / dis + y2) / 2
    r = (dis + R) / 2
    print (x, y, r)
    
