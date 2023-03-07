n=input('请输入题目编号:')
switch n
    case 1
        %% 求函数极值
        clear,clc
        f1=@(x) (-exp(x).*x.*sin(x))
        ezplot(f1,[0,9]);
        [x0,y0]=fminbnd(f1,8,9)
        y0=-y0
    case 2
        %% 线性规划
        clear,clc
        c=[-2.5,-5,-10];
        A=[-2.5,-5,-10;
            -2,-2,1];
        b=[-50;0];
        Aeq=[1,1,1];
        beq=[100];
        lb=[10;0;20];
        ub=[30;90;80];
        [x,fval]=linprog(c,A,b,Aeq,beq,lb,ub);
        fval=-fval
        
    case 3
        %% 综合训练
        clear,clc  
        c=[-17,-15]';
        A=[3,5;
            6,5;
            2,6];
        b=[150;160;180];
        lb=zeros(2,1);
        [x,fval]=linprog(c,A,b,[],[],lb);
        fval=-fval
        
    case 4
        %% 模拟学生到达图书馆时间
        clear,clc
        last=rand(1,1)*5;
        time_point=last;
        for i=2:100
            t=rand(1,1)*5;
            time_point=[time_point,last+t];
            last = last + t;
        end
        plot([1:100],time_point)
        time_point=reshape(time_point,10,10)'
        
    case 5
        %% 模拟学生达到图书馆时间和人数
        clear,clc
        sum=rand(1,1)*5
        time_point = sum;
        cnt = 0;
        while 1==1
            cnt = cnt + 1;
            t = rand(1,1)*5;
            sum = sum + t;
            time_point=[time_point,sum];
            if sum > 1800 
                sum = sum - t;
                break;
            end
        end
        sprintf('到达人数=%d',cnt)
        
    case 6
        %% 蒙特卡洛模拟求解非线性规划
        N=100000
        tmp=0;
        m=inf;
        x=[];

        for i=1:N
            x1=15*rand(1);
            x2=9*rand(1);
            x3=fix(25*rand(1));
            if (3.*x1+2.*x2+6.*x3<=20)&&(4.*x1+5.*x2+2.*x3<=21)
                tmp=2.*(x1-1).*(x1-1)+3.*(x2-4).*(x2-4)+x1.*x2+(2.*x3-5).*(2.*x3-5)
                if tmp<m
                    m=tmp;
                    x=[x1;x2;x3];
                end
            end
        end
         m
         x
        sprintf('近似最优解=%d\nx1=%d,x2=%d,x3=%d',m,x(1),x(2),x(3))
        
end