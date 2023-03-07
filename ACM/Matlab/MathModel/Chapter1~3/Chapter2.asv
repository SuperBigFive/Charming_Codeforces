format long g
n=input("Input the question number:");

switch n
    
    case 1
        %% 数学建模例题2.6
        clear;clc
        cost=[15,13.8,12.5,11,14.3;
            14.5,14,13.2,10.5,15;
            13.8,13,12.8,11.3,14.6;
            14.7,13.6,13,11.6,14];
        c=[];
        for i=1:4
            c=[c,cost(i,:)];
        end
        intcon=[1:20];
        A=zeros(4,20);
        for i=1:4
            A(i,5*(i-1)+1:5*(i-1)+5)=ones(1,5);
        end
        Aeq=zeros(5,20);
        for i=1:5
            Aeq(i,[i,i+5,i+10,i+15])=1;
        end
        beq=ones(5,1);
        b=2*ones(4,1);
        lb=zeros(20,1);
        ub=ones(20,1);
        [x,fval]=intlinprog(c,intcon,A,b,Aeq,beq,lb,ub);
        x
        fval
        
    case 2
        %% 数学建模例题2.7(算错了)
        x=[9.4888,8.7928,11.5643,5.6756,9.8497,9.1756,13.1385,15,4663,15.5464];
        y=[5.6817,10.3868,3.9294,4,4325,9.9658,17.6632,6.1517,11.8569,8.8721,15.5868];
        c=[ones(10,1);zeros(100,1)];
        intcon=[1:110];
        A=zeros(120,110);
        for i=1:10
            A(i,10+10*(i-1)+1:10+10*(i-1)+10)=1;
        end
        for i=11:110
            A(i,i)=sqrt((x(fix((i-1)/10))-x(i-10*fix((i-1)/10)))^2+(y(fix((i-1)/10))-y(i-10*fix((i-1)/10)))^2);
            A(i,fix((i-1)/10))=-10;
        end
        for i=1:10
            A(11*i,11*i)=0.1;
        end
        for i=111:120
            for j=1:10
            A(i,10*(j-1)+10+i-110)=-1;
            end
        end
        b=[5*ones(10,1);zeros(100,1);-1*ones(10,1)];
        lb=zeros(110,1);
        ub=ones(110,1);
        [x,fval]=intlinprog(c,intcon,A,b,[],[],lb,ub);
        x=reshape(x,11,10)
        fval
        
    case 3
        %% 数学建模习题2.1
        clear;clc
        c=[-1;-1;1];
        A=[-2,3,1;
            -1,1,0];
        b=[3,0];
        lb=zeros(3,1);
        ub=ones(3,1);
        intcon=[1,2,3];
        [x,fval]=intlinprog(c,intcon,A,b,[],[],lb,ub);
        x
        fval=-fval
        
    case 4
        %% 数学建模习题2.2
        clear;clc
        c=ones(6,1);
        A=-[1,1,1,0,0,0;
            0,1,0,1,0,0;
            0,0,1,0,1,0;
            0,0,0,1,0,1;
            1,1,1,0,0,0;
            0,0,0,0,1,1;
            1,0,0,0,0,0];
        b=-ones(7,1);
        intcon=[1:6];
        lb=zeros(6,1);
        ub=ones(6,1);
       [x,fval]=intlinprog(c,intcon,A,b,[],[],lb,ub);
       x
       fval
       
    case 5
        %% 数学建模习题2.3
        clear;clc
        c=-[4;6;7;7;7;7;
            2;4;6;8;9;10;
            3;5;7;8;8;8;
            4;5;6;6;6;6];
        intcon=[1:24];
        A=zeros(5,24);
        for i=1:24
            A(1,i)=i-fix((i-1)/6)*6;
        end
        for i=2:5
            A(i,6*(i-2)+1:6*(i-2)+6)=1;
        end
        b=[6;ones(4,1)];
        lb=zeros(24,1);
        ub=ones(24,1);
        [x,fval]=intlinprog(c,intcon,A,b,[],[],lb,ub);
        x=reshape(x,6,4)
        fval=-fval
        
    case 6
        %% 数学建模习题2.6
        c=[20,90,80,70,30]';
        A=[-1,-1,0,0,1;
            0,0,-1,-1,0;
            3,0,2,0,0;
            0,3,0,2,1];
        b=[-30,-30,120,48]';
        intcon=[1:5];
        lb=zeros(5,1);
        [x,fval]=intlinprog(c,intcon,A,b,[],[],lb);
        x
        fval
        
    case 7
        %% 数学建模习题2.7
        c=-[2,1]';
        A=[0,5;6,2;1,1];
        intcon=[1,2];
        b=[15,24,5];
        lb=[0;0];
        [x,fval]=intlinprog(c,intcon,A,b,[],[],lb);
        x
        fval=-fval
        
    case 8
        %% 数学建模习题2.8 指派问题
        C=[6,7,5,8,9,10;
            6,3,7,9,3,8;
            8,11,12,6,7,9;
            9,7,5,4,7,6;
            5,8,9,6,10,7;
            9,8,7,6,5,9];
        c=[];
        for i=1:6
            c=[c,C(i,:)];
        end
        A=zeros(12,36);
        for i=1:6
            A(i,6*(i-1)+1:6*(i-1)+6)=-1;
        end
        for i=7:12
            for j=1:6
            A(i,6*(j-1)+i-6)=-1;
            end
        end
        b=-ones(12,1);
        lb=zeros(36,1);
        ub=ones(36,1);
        [x,fval]=intlinprog(c,intcon,A,b,[],[],lb,ub);
        x=reshape(x,6,6)
        fval
        
    case 9
        %% 数学建模习题2.10(TSP旅行商问题)
        
end
