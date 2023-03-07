function [C,D,E]=test_cm14
rand('seed',2777)
A=fix(20*rand(10,10));
B=fix(20*rand(10,10));
C=A*B;
D=A+B;
E=(A')*(B');
end