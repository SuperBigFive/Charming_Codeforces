clear, clc
load data_customer.txt

%% 数据读入
x = data_customer (:, 1);
y = data_customer (:, 2);
plot (x, y, 'c.')
%% %% %% %% %% %%%

%% 绘制第一条拟合曲线
p = polyfit (x, y, 1);
yy = polyval (p, x);
hold on
plot (x, yy ,'b-')

x1 = [];
y1 = [];
x2 = [];
y2 = [];
%% %% %% %% %% %%%

%% 绘制第二三条拟合曲线
for i =1 : 1000
    if y(i) > yy(i) && x(i) <= 114.4
        y2 = [y2; y(i)];
        x2 = [x2; x(i)];
    end
    if y(i) <= yy(i) && x(i) <= 114.4
        y1 = [y1; y(i)];
        x1 = [x1; x(i)];
    end
end

p = polyfit (x1, y1, 1);
y1 = polyval (p, x1);
hold on 
plot (x1, y1, 'b-')

f1 = @(x) (p(2) + p(1)*x);

p = polyfit (x2, y2, 1);
y2 = polyval (p, x2);
hold on 
plot (x2, y2, 'b-')

f2 = @(x) (p(2) + p(1)*x);
%% %% %% %% %% %%%

%% 部分参数的设置
accept_scale = 0.13;
up_x = zeros (1, 5);
up_y = zeros (1, 5);
down_x = zeros (1, 5);
down_y = zeros (1, 5);
key_point = zeros(2, 10);
mmin = inf;
tmp_min = inf;
ans_point = zeros (2, 10);
cnt = zeros (1,10);
cntt = 500000;
%% %% %% %% %% %%%

%% 主要部分
for k = 1 : cntt
    dis_sum = 0;
    %% 随机投点（放两个点很近. 优化1）
    for i = 1 : 5
        while 1
            flag = 0;
            up_x(i) = 114.0 +(rand()-0.5)* 0.75;
            up_y(i) = f1(up_x(i)) + (rand()-0.5)* 2 * accept_scale;
            for j = 1 : 2*(i - 1)
                 dis = (key_point(1, j) - up_x(i))^2 + (key_point(2,j) - up_y(i))^2; 
                 if dis <= 0.005
                     flag = 1;
                     break;
                 end
            end
            if flag ~= 1 
                break;
            end
        end
        key_point(1, 2*i-1) = up_x(i);
        key_point(2, 2*i-1) = up_y(i);
        
        while 1
            flag = 0;
            down_x(i) =114.0 + (rand()-0.5)* 0.75;
            down_y(i) = f2(down_x(i)) + (rand()-0.5)* 2 * accept_scale;%%随机模拟投点
            for j = 1 : 2*(i - 1) + 1
                 dis = (key_point(1, j) - down_x(i))^2 + (key_point(2,j) - down_y(i))^2; 
                 if dis <= 0.005
                     flag = 1;
                     break;
                 end
            end
            if flag ~= 1 
                break;
            end
        end
        key_point(1, 2*i) = down_x(i);
        key_point(2, 2*i) = down_y(i);
    end
    %% %% %% %% %% %%%
    
    for i = 1 : 10
        cnt(i) = 0;
    end
    %% 从顾客1枚举到顾客1000
    for i = 1 : 1000
        tmp_min = inf;
        %% 找到离顾客i最近的投放点
        for j = 1 : 10
            dis = (key_point(1, j) - x(i))^2 + (key_point(2,j) - y(i))^2;
            if tmp_min > dis
                tmp_min = dis;
                tmp_bl = j;
            end
        end
        cnt(tmp_bl) = cnt(tmp_bl) + 1;
        dis_sum = dis_sum + tmp_min;
    end
    %% 如果当前每个乘客距离离他最近的点的距离和
    %% 比之前得到的更小，则更新答案
    if dis_sum < mmin 
        for j = 1 : 10
            flag = 0;
            %% 优化2，防止某个点分配到的顾客太少的情况
            if cnt(j) < 30
                flag = 1;
                break;
            end
        end
        if flag ~= 1 
            ans_point = key_point;
            mmin = dis_sum;
        end
        if flag == 1
            cntt = cntt + 1;
        end
    end
end

bl = zeros (1000, 1);
%% 得到每个顾客归属的分区
for i = 1 : 1000
    tmp_min = inf;
     for j = 1 : 10
            dis = (key_point(1, j) - x(i))^2 + (key_point(2,j) - y(i))^2;
            if tmp_min > dis
                tmp_min = dis;
                bl(i) = j;
            end
     end
end

hold on
plot (ans_point (1,:), ans_point (2,:), 'rx')
