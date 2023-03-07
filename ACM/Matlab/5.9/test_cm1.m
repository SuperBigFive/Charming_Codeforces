function A=test_cm1
rand('seed',1319)
A=fix(7*rand(8,8));
A([3,5],:)=A([3,5],:)*2;
A(:,[2,3])=[];
end
