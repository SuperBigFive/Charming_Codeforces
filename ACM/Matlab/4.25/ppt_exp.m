format long 
n=input('Please input a number:');
    %% 最优化算法
    %可用于对目标函数极小化（极大化）
    % 需要有约束条件（=，>=)
    % 迭代下降算法
    % 命令:fminunc():多变量无约束
    %          fmincon():多变量有约束
    %          linprog():线性规划
    %          intlinprog():混合整数线性规划
    %          ga():遗传算法
    %          fminbnd():单变量无约束
    %          fminsearch():多变量无约束
        
switch n
    case 1
        %% 寻找某公式最合适参数
        % ->个点与真实值的差的平方的和最小
        % ->最优化问题
        clc,clear all;
        syms x1 t
        R=(x1./(t+28));
        ti=1:10;
        Ri=[4.27,4.68,4.36,4.26,3.95,3.33,3.37,3.58,3.76,3.70];
        F=sum((Ri-subs(R,t,ti)).^2);
        Xmin=double(solve(diff(F,x1)))
        Fmin=double(subs(F,x1,Xmin))
        
    case 2
        %% [xmin,ymin]=fminbnd(fun,x1,x2)
        % 求解一元函数在区间内的最小值
        % 内联函数可以直接将函数名传入形参
        clc,clear all;
        fun=inline('0.5-x*exp(-x^2)');
        [xmin,ymin]=fminbnd(fun,0,2);
        ezplot(fun,[0,2])
        hold on
        plot(xmin,ymin,'o')
        
    case 3
        %% 求区间极小值
        clc,clear;
        fun=inline('x*sin(3*x)');
        x=[];
        y=[];
        [tempx,tempy]=fminbnd(fun,0,0.1);
        for i=0.1:0.1:5.9
              [xmin,ymin]=fminbnd(fun,i,i+0.1);
              if xmin==tempx
                  x=[x,xmin];
                  y=[y,ymin];
              end
              tempx=xmin;
              if xmin==6
                  x=[x,xmin];
                  y=[y,ymin];
              end
        end
        ezplot(fun,[0,6]);
        hold on
        plot(x,y,'o')
        
    case 4
        %% 梯子问题
        clc,clear;
        %syms h
        %L=(h+3)/h*sqrt(h^2+4);
        %dl=diff(L);
        %hmin=solve(dl,'h')
        %lmin=subs(L,h,hmin)
        
        L=inline('(h+3)/h*sqrt(h^2+4)');
        [xmin,ymin]=fminbnd(L,0,500)
    
    case 5
        %% 最大利润
        clc,clear;
        c=[-500,-600]';
        A=[-1,-1;
            1,0;
            0,1];
        b=[-5000,5000,3000]';
        lb=zeros(2,1);
        [x,fval]=linprog(c,A,b,[],[],lb);
        x
        fval=-fval
        
    case 6
        %% 吨获利最大
        clc,clear;
        c=[-7000,-12000]';
        A=[9,5;
            4,5;
            3,10];
        b=[360,200,300]';
        [x,fval]=linprog(c,A,b);
        x
        fval=-fval
        
    case 7
        %% 产品总价值最大
        clc,clear;
        c=[-7,-5]';
        A=[3,2;
            4,6;
            0,7];
        b=[90,200,210]';
        lb=zeros(2,1);
        [x,fval]=linprog(c,A,b,[],[],lb);
        x
        fval=-fval*10000  
        
    case 8
        %% 估算积分
        clc,clear;
        cnt=0;
        for i=1:100000
            x=rand(1)+1;
            y=unifrnd(0,sin(1),1,1);
            if y<=sin(x)/x
                cnt=cnt+1;
            end
        end
        I=cnt/100000*sin(1)
        
    case 9
        %% 估计圆周率
        clc,clear;
        cnt=0;
        for i=1:100000
            x=2*rand(1)-1;
            y=2*rand(1)-1;
            if x^2+y^2<=1
                cnt=cnt+1;
            end
        end
        Pi=cnt/100000*4
        
    case 10
        %% 估算面积
        clc,clear;
        cnt=0;
        for i=1:100000
            x=rand(1);
            y=rand(1);
            if y>=x^2&&y<=sqrt(x)
                cnt=cnt+1;
            end
        end
        S=cnt/100000
    
    case 11
        %% 求解最小值
        clc,clear;
        f=inline('3*(x-1)^2+4*(y-2)^2');
        mval=inf;
        for i=1:100000
            x=6*rand(1)-3;
            y=10*rand(1)-5;
            if f(x,y)<mval
                mval=f(x,y);
                mx=x;
                my=y;
            end
        end
        mx,my
        mval
        
    case 12
        %% 估算二重积分
        clc,clear;
        V=0;
        for k=1:10
            cnt=0;
            for i=1:1000000
                x=4*rand;
                y=3*rand-1;
                z=16*rand;
                if x>=y^2&&x<=y+2&&z<=x*y^2
                    cnt=cnt+1;
                end
            end
            V=V+cnt/1000000*192;
        end
        V=V/10
        
    case 13
        %% 相遇问题
        clc,clear;
        cnt=0;
        for i=1:100000
            x=24*rand;
            y=24*rand;
            if x<=y&& (y-x<=2||x+24-y<=1)
                cnt=cnt+1;
            end
            if y<x&& (x-y<=1||y+24-x<=2)
                cnt=cnt+1;
            end
        end
        P=cnt/100000
end       
        
        