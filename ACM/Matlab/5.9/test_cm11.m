function r=test_cm11
f1=@(x) (x-15);
f2=@(x) (1-x.*x);
f3=@(x) (2.*x+10);
x=-4:0.2:4;
r=(x<-5).*f1(x)+(x>=-5&x<=5).*f2(x)+(x>5).*f3(x);
end