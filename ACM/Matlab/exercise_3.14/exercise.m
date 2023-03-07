clear
clc
disp('课堂练习1')
a=[40,20,30;30,10,50]
b=[400;300;500]
c=a*b
sprintf('第一季度产品利润=%d',c(1))
sprintf('第二季度产品利润=%d',c(2))

clear
disp('课堂练习2')
A=[-1 -1;1 1;]
B=[-2 2;2 -1]
A*B
B*A

clear
disp('课堂练习3')
A=rand(5,5)
B=rand(5,5)
if (A*B)'==B'*A'
    disp('等式成立')
else
    disp('等式不成立')
end

clear
disp('课堂练习4')
linspace(-1,100,100)

clear
disp('课堂练习5')
A=ones(100,20)
B=zeros(100,50)
C=[A,B]

clear
disp('课堂练习6')
A=ones(100,20)
A(:,[17,19])=[]
A

clear
disp('课堂练习7')
n=input('请输入一个整数n:')
a=rand(1,n)
s=0
for i=1:n
    s=s+a(i)*a(i)
end
if mod(n,2)
    s=s-a(n)*a(n)
else
end

clear
disp('课堂练习8')
A=rand(20,20)
B=A\eye(20,20)

clear
disp('课堂练习9')
sprintf('%s%d%s%d','电子科技大学-',985,'-',211)

clear
disp('课堂练习10')
A=[-1,-1;1,1]
sum(A,1)
sum(A,2)
sum(sum(A,1))
disp('over')