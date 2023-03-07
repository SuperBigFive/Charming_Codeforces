function [c, d, e] = test_cm10
rand ('seed', 1861)
A1 = fix (20*rand (10, 10));
A2 = fix (20*rand (10,10));
c = A1*A2;
d = A1 + A2;
e = (A1')*(A2');
end