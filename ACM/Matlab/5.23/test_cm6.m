function [yt] = test_cm6
rand ('seed', 2549)
v = fix (20*rand (1,50));
f = @(x) (3*x*x - x*x*x);
mmax = -999999;
mmin = 999999;
for i= 1: 50
    if f(v(i)) > mmax
        mmax = f(v(i));
    end
    if f(v(i)) < mmin
        mmin = f(v(i));
    end
end
yt = mmax - mmin;
end