function r=test8_cm
rand('seed',1759)
A=fix(20*rand(10,10));
A=[A;fix(5*rand(1,10))];
A(:,[1,3,7])=[];
c=A(1,:);
A(1,:)=A(2,:);
A(2,:)=c;
r=A;
end