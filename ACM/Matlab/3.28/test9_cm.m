function s=test9_cm
s=[];
for i=50:200
    if fix(i/7)==i/7|fix(i/15)==i/15
        s=[s,i*i];
    end
end
s=sum(s');
end
