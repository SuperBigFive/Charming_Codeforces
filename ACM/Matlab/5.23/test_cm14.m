function r = test_cm14
rand ('seed', 127)
v = 65 + fix (10*rand (1,300));
v = char (v)
r = [];
for i = 1 : 299
    if v(i) == 'C' && v(i+1) == 'D'
        r = [r,i];
    end
end
end