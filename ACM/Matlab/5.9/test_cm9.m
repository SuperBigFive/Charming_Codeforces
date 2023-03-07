function z=test_cm9
[x,y]=meshgrid([-2:0.05:2]);
f=@(x,y) (cos(1+exp(x.*y)).*sin(x.*x+3.*y.*y));
z=f(x,y);
end