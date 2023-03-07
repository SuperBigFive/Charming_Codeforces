function [x,y]=test12_cm
f1=@(t)(2+sin(t).^2);
f2=@(t)(sin(t).^2);
t=0:pi/10:2*pi;
x=f1(t);
y=f2(t);
end