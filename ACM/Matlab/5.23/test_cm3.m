function r = test_cm3
r = 0;
for i = 1 : 1000
    if  fix(i/3) == i/3 || fix (i/4) == i/4 && fix (i/48) ~= i/48
        r = r + i;
    end
end
end