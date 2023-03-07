function a=test_cm5
rand('seed',127)
a=char(97+fix(26*rand(1,300)));
for i=1:300
    if a(i)>='a'&&a(i)<='h'
        a(i)=[];
    end
end
a=sort(a,'ascend');
end