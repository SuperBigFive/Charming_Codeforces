function r=test10_cm
rand('seed',137)
v=fix(15*rand(1,50));
z1=find((v-10).^2<=4);
z2=v(z1);
r=sum(z2');
end
