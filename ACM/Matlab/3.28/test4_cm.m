function A=test4_cm
n=20;
A=zeros(5,n);
w=[1.23,1.24,1.32,1.19,1.17];
for i=1:5
    for j=1:n
        A(i,j)=w(i)^j;
    end
end
end
