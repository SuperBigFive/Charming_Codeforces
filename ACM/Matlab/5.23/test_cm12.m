function z = test_cm12
f = @(x, y) (sin(exp(x.*y)).*cos(2.*x.*x+y.*y))
[x,y] = meshgrid (-2:0.05:2,-2:0.1:3);
z = f(x,y);
end