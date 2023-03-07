disp('2022.4.11基础实验作业中的matlab习题')
n=input('请输入一个数字（以用来查看题解):');
switch n
    case 1
        %% 题目1 逆序赋值
        clear;clc
        format long 
        v=linspace(55,97,100);
        w=[];
        for i=100:-1:1
            w=[w,v(i)];
        end
        w=reshape(w,20,5)
    case 2
        %% 题目2 循环赋值
        clear;clc
         format short g
         format long g
        x(1)=0;
        x(2)=1;
        for i=3:40
            x(i)=x(i-1)+2*x(i-2);
        end
        x=reshape(x,10,4)
        
    case 3
        %% 题目3 循环语句与枚举法
        %function [a,b]= question_3()
        clear;clc
        k=1;
        for i=1:1000
            t=(i*i-i)/100;
            if fix(t)==t&&t<=1000&&t>=1
                a(k)=i;
                b(k)=t;
                k=k+1;
            end
        end
        a
        b
        %end
        %这里注释掉，否则matlab报错
    case 4
        %% 题目4 (1) 绘制股票交易数据图
        clear;clc
        load SH600004.mat
        x=[1:100]';
        y=M(end-99:end,5);
        subplot(1,2,1)
        plot(x,y,'-*');
        
    case 5
        %% 题目4 (2)涨幅变化曲线和散点图
        y=zeros(1,100);
        for i=100:-1:1
            y(101-i)=(M(end-i,5)-M(end-i-1,5))/M(end-i,5);
        end
        x=1:100;
        subplot(1,2,2)
        plot(x,y,'-*r');
        bar(x,y,'r');
        
    case 6
        %% 1.2 综合训练
        clear;clc
        len = 1200;
        method=[64,85];
        max_1=fix(len/method(1));
        max_2=fix(len/method(2));
        cnt=0;
        for i=0:max_1
            j=fix((len-i*method(1))/85);
            if  i + j==0
                continue
            end
            if  i*method(1) + j*method(2) > 1200 
                break
            end
            cnt=cnt+1;
            rest=1200-i*method(1) - j*method(2) ;
            mat_info(cnt,1)=i;
            mat_info(cnt,2)=j;
            mat_info(cnt,3)=rest;
        end
        disp('切割方式信息矩阵:');
        output=[];
        for i=1:cnt
            output=char(output,sprintf('64cm数量:%d,85cm数量:%d,余料长度:%d',mat_info(i,1),mat_info(i,2),mat_info(i,3)));
        end
        output=char(output,sprintf('切割方式数量:%d',cnt))
end