function [ymax,ymin]=test7_cm
rand('seed',1381)
v=fix(20*rand(1,50));
f=@(x)(cos(x.*x)+2*sin(x.^3));
y=f(v);
[ymax,~]=max(y);
[ymin,~]=min(y);
end