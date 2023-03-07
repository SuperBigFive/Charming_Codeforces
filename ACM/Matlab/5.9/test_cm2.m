function [maxvalue,maxidx]=test_cm2
rand('seed',127)
v=round(200*rand(1,1000));
max=-1000;
for i=1:1000
    if max<v(i)
        max=v(i);
        maxidx=i;
    end
end
maxvalue=max;
end