function [a,b]=test_cm6
A=[1,6,4;3,8,2];
B=[7,2,5;
    6,1,3];
a=2.*A-B;
b=B+3.*A;
end