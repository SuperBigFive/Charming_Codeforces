%% 随机取值
x=fix(randn(1,6)*10)
y=fix(randn(1,6)*10)
xy=fix(randn(1,12)*10)
input=[6,6,6,x,y,xy]

%% 双射函数
x=fix(randn(1,6)*10)
y=fix(randn(1,6)*10)
input=[6,6,6,x,y,x,y]

%% 单射函数（非满）
x=fix(randn(1,6)*10)
y=fix(randn(1,7)*10)
input=[6,7,6,x,y,x,y(1:6)]

%% 满射函数（非单）
x=fix(randn(1,7)*10)
y=fix(randn(1,6)*10)
input=[7,6,7,x,y,x,y,fix(randn(1,1)*10)]
