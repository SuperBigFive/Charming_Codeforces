function a=test11_cm
f=@(x)(2.*x.*sin(x.^2));
x=-2:0.01:2;
a=f(x);
end