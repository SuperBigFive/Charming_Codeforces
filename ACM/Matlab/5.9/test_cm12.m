function c=test_cm12
s=[1];
m=[log(1)];
for i=2:100
    tmp=1/i;
    s=[s,s(i-1)+tmp];
    m=[m,log(i)];
end
c=s-m;
end