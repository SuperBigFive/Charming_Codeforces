p,q=input().split()
p=int(p)
q=int(q)

def S5(n):
    return n*n*(n+1)*(n+1)*(2*n**2+2*n-1)//12
min_val=1000000000000000000
cur_money=0
for i in range(1,10000):
    cur_money=cur_money-p
    min_val = min(min_val, cur_money)
    cur_money=cur_money+q*(i**5)
    min_val=min(min_val,cur_money)
x=-min_val


def check(d):
    t=q*S5(d)-p*d+x
    if(t>=10**99):
        return True
    else:
        return False

l=1
r=10**18
#[1,l]不行,[r,+无穷大]可行
while(l+1<r):
    #print("l:"+str(l))
    #print("r:"+str(r))
    mid=(l+r)//2
    if(check(mid)):
        r=mid
    else:
        l=mid
y=r
print(x,y)