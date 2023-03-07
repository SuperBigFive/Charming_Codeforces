function a=test_cm10
a=[];
for i=1:5000
    if i*i*i/333==fix(i*i*i/333)
        a=[a,i];
    end
end
end