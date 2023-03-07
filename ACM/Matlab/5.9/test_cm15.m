function B=test_cm15
rand('seed',59)
A=5*rand(3,5);
B=[];
for i=1:3
    for j=1:5
        if A(i,j)>1
            B=[B,A(i,j)];
        end
    end
end

end