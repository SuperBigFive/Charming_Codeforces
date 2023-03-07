function A =test_cm5
rand ('seed', 1283)
A = fix (20*rand (10,10));
a = A(2,:);
A(2,:) = A(5,:);
A(5,:) =a;
A(:,[3,7]) = [];
end