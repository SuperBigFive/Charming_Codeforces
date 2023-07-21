n = int (input ()); s = input ()
x, y = 0, 0; cost = 0; last = -1
for ch in s :
    if ch == 'R' : x += 1
    else : y += 1
    if x != y :
        if last == -1 : last = x > y
        elif last != (x > y) : last = x > y; cost += 1
print (cost)
