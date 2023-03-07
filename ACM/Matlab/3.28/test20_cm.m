function v=test20_cm
x=0:0.1:10;
v=fun(x);
end
function r=fun(a)
f=@(x) ((x<=4).*(2.*x-x.^2)+(x>4).*log(x-1));
r=f(a);
end
