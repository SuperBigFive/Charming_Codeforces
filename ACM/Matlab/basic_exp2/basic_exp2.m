n=input('请输入题目编号:');
switch n
    case 1
        %%  方程求根
        % function xp=ques1
        clear,clc
        f=@(x) (2*x^3-3*x^2+4*x-5);
        xp=fzero(f,-5);
        % end
    
    case 2
        %% 解常微分方程
        clear,clc
        [t1,y1]=ode23(@(t,y) 0.02*(1-0.001*y*t)*t,[0:0.5:10],10);
        y2=10*ones(21,1);
        for k=2:21
            y2(k)=y2(k-1)+0.02*(1-0.001*y2(k))*y2(k)*0.5;
        end
        y=[y1,y2]'
        
    case 3
        %% 二次多项式拟合
        % function [p,v]= myfun
        clear,clc
        % 曲线拟合
        % y= 2.00 + 1.00*(x-25.00).^2
        % 多项式系数: 1  -50  627
        % 多项式系数: 
        % y=1.00 x^2 + -50.00 x + 627.00
        x=[   20.05  22.09  24.13  26.24  28.11  30.29  32.09  34.23 
              36.23  38.2  40.27  42.27  44.07  46.05  48.47  50.08];
        y=[   26.5  10.46  2.75  3.53  11.67  29.98  52.26  87.19 
              128.11  176.24  235.17  300.25  365.66  445.1  552.84  631];
        p=polyfit(x,y,2);
        x=[25:0.4:60];
        v=polyval(p,x)
       %  end
        
    case 4
        %% 综合任务 
        % function r=ques4
        x0=[2;0];
        tn=[0:0.1:100];
        [t,y]=ode45(@vdpol,tn,x0)
        plot(t,y(:,1),'r--')
        xlabel('t')
        ylabel('x')
        % end
        % function dfun=vdpol(t,x)
        % dfun=[x(2);20*(1-x(1)*x(1))*x(2)+0.5*x(1)];
        % end
end