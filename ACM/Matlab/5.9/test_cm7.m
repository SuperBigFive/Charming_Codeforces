function A=test_cm7
s=[0.9,1.02,0.8,0.7];
m=[0.9,1.02,0.8,0.7];
n=6;
A=[];
for i=1:n*n
    A=[A;m];
    m=m.*s;
end
end