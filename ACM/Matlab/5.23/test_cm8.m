function A = test_cm8
s = [0.9; 1.3; 0.8; 0.7];
n = 6;
A= s;
for i = 2 : n*n
    A = [A , A(:,i - 1).*s];
end
end