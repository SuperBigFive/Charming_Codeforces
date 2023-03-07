T=input()
T=int(T)
for i in range(0,T):
    x, y, p = input().split()
    x = float(x)
    y = float(y)
    p = float(p)
    t=1-(1/p)
    pow=int(x)//int(y)
    ans=(t**(pow+1)*(x%y)+(t**pow)*(y-(x%y)))/y
    ans=1-ans
    print(ans)
