format long g
n=input("Input the number of the question:")

switch n
    
    case 1
        %% 线性规划的投料问题
        row=[1.25 8.75 0.5 5.75 3 7.25];
        line=[1.25 0.75 4.75 5 6.5 7.25];
        row_a=row-5;
        row_b=row-2;
        line_a=line-1;
        line_b=line-7;
        distance_a=zeros(1,6);
        distance_b=zeros(1,6);
        for i=1:6
            distance_a(i)=sqrt(row_a(i)^2+line_a(i)^2);
            distance_b(i)=sqrt(row_b(i)^2+line_b(i)^2);
        end
        c=[distance_a,distance_b]';
        A=zeros(2,12);
        A(1,1:6)=1;
        A(2,7:12)=1;
        b=[20,20]';
        Aeq=zeros(6,12);
        for i=1:6
            Aeq(i,i)=1;Aeq(i,i+6)=1;
        end
        beq=[3,5,4,7,6,11]';
        lb=zeros(12,1);
        [x,fval]=linprog(c,A,b,Aeq,beq,lb,[]);
        x=reshape(x,6,2)
        fval
        
    case 2
        %% 整形规划的小例题1
        c=[-20,-10]';
        intcon=[1,2];
        A=[5,4;2,5];
        b=[24,13]';
        lb=[0,0];
        [x,fval]=intlinprog(c,intcon,A,b,[],[],lb);
        x
        fval=-fval
        
    case 3
        %% 整形规划的小例题2
        c=[18,23,5]';
        intcon=[3];
        A=[107,500,0;-107,-500,0;72,121,65;-72,-121,-65];
        b=[50000,-500,2250,-2000]';
        lb=zeros(3,1);
        [x,fval]=intlinprog(c,intcon,A,b,[],[],lb);
        x
        fval
        
    case 4
        %% 整形规划的小例题3
        c=[-3,-2,-1]';
        intcon=3;
        A=[1,1,1];
        b=7;
        Aeq=[4,2,1];
        beq=12;
        lb=[0,0,0];
        ub=[inf,inf,1];
        [x,fval]=intlinprog(c,intcon,A,b,Aeq,beq,lb,ub);
        x
        fval
        
    case 5
        %% 清风课后习题1
        
    case 6
        %% 清风课后习题2
        c=[3100,3100,3100
            3800,3800,3800
            3500,3500,3500
            2850,2850,2850]';
        A=zeros(10,12);
        A(1,1:3)=1;
        A(2,4:6)=1;
        A(3,7:9)=1;
        A(4,10:12)=1;
        A(5,1:3:10)=1;
        A(6,2:3:11)=1;
        A(7,3:3:12)=1;
        A(8,1:3:10)=[480,650,580,390];
        A(9,2:3:11)=[480,650,580,390];
        A(10,3:3:12)=[480,650,580,390];
        b=[18,15,23,12,10,16,8,6800,8700,5300]';
        Aeq=[8,-5,0,8,-5,0,8,-5,0,8,-5,0;
            0,1,-2,0,1,-2,0,1,-2,0,1,-2];
        beq=[0,0]';
        lb=zeros(12,1);
        [x,fval]=linprog(-c,A,b,Aeq,beq,lb);
        x
        fval=-fval
        
    case 7
        %% 背包问题
        clear;
        clc;
        weight=[6,3,4,5,1,2,3,5,4,2];
        price=[540,200,180,350,60,150,280,450,320,120];
        c=-price;
        intcon=[1:10];
        A=weight;
        b=30;
        lb=zeros(10,1);
        ub=ones(10,1);
        [x,fval]=intlinprog(c,intcon,A,b,[],[],lb,ub);
        x
        fval=-fval
        
    case 8
        %% 指派问题：混合接力游泳
        clear;clc
        people1=[66.8,75.6,87,58.6];
        people2=[57.2,66,66.4,53];
        people3=[78,67.8,84.6,59.4];
        people4=[70,74.2,69.6,57.2];
        people5=[67.4,71,83.8,62.4];
        c=[];
        for i=1:4
            c=[c,people1(i),people2(i),people3(i),people4(i),people5(i)];
        end
        intcon=[1:20];
        A=zeros(5,20);
        for i=1:5
            for j=1:4
                A(i,i+5*(j-1))=1
            end
        end
        b=ones(5,1);
        Aeq=zeros(5,20);
        for i=1:4
            Aeq(i,5*(i-1)+1:5*(i-1)+5)=1;
        end
        Aeq(5,1:end)=1;
        beq=ones(5,1);
        beq(5)=4;
        lb=zeros(20,1);
        ub=ones(20,1);
        [x,fval]=intlinprog(c,intcon,A,b,Aeq,beq,lb,ub);
        x=reshape(x,5,4)
        fval
        
    case 9
        %% 钢管切割问题
        %改进：枚举法找到所有切割方法
        format short
        clear;clc
        c=ones(7,1);
        intcon=[1:7];
        Aeq=[6,4,2,0,4,1,1;%这里最好是不等式约束
            0,1,2,3,0,1,0;
            0,0,0,0,1,1,2];
        beq=[100,100,100]';
        lb=zeros(7,1);
        [x,fval]=intlinprog(c,intcon,[],[],Aeq,beq,lb);
        x
        fval
        
    case 10
        %% 
end