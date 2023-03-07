function A = test_cm13
rand ('seed', 59)
A = rand (5,8);
for i = 5 : -1 : 1
    tmp = 0;
    for j = 1 : 8
        tmp = tmp + A(i,j);
    end
    if tmp < 4
        A(i,:) = [];
    end
end
end
    