function r=test_cm13
r=[];
for i=1:5000
    if mod(i*i*i,10000)==8888
        r=[r,i];
    end
end
end