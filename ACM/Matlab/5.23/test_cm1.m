function v =test_cm1
v= [];
for i= 1 : 5000
    if i*i*i/333 == fix (i*i*i/333)
        v = [v, i];
    end
end
end