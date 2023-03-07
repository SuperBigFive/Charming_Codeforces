function [ymax,ymin]=test_cm4
rand('seed',2549)
v=fix(20*rand(1,50));
f=@(x) (sin(x)+2.*sin(2.*x)+3.*sin(3.*x));
y=f(v);
ymax=-100000;
ymin=100000;
for i=1:50
    if ymax<f(i)
        ymax=f(i);
    end
    if ymin>f(i)
        ymin=f(i);
    end
end
end