function s=test5_cm
couter=1;
value=zeros(1,3);
for i=1000:2000
    if fix(i/53)==i/53
        value(couter)=i;
        couter=couter+1;
    end
    if couter==4
        break;
    end
end
s=[value(2),value(3)];
end