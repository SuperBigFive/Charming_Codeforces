clear;
close all;
format long g;
N=input('Please input the numebr of the example of exercises:')

switch N

    case 1
        %% Example 1
        name=input('Please input your name:','s');
        if name(1)>='a' && name(1)<='h'
            disp(['Hello ', name]); 
        else
            disp(['Welcome, ' name]);
        end
        
    case 2
        %% Example 2
        marks=input('Please input your marks:');
        if marks>=90
            disp('Great')
        elseif marks>=80
            disp('Good')
        elseif marks>=70
            disp('Normal')
        else
            disp('Bad, I advice you to remark yourself')
        end
        
    case 3
        %% Example 3
        marks=input('Please input your marks:');
        marks=fix(marks/10);
        switch marks
            case 9
                disp('Wow,u are so excellent!');
            case 8
                disp('U did a good job,but there is still space for u to progress.');
            case 7
                disp('U should be more hard.');
            case 6
                disp('What a low score u have got!Get out here!');
            otherwise
                disp('Who are u?');
        end
        
    case 4
        %% Example 4
        N=input('How many numbers do u want:');
        f=[1,1];
        for i=3:N
            f=[f,f(i-1)+f(i-2)];
        end
        f
        f(20)
           
    case 5
        %% Example 5
        m=zeros(5,4);
        for i=1:5
            for j=1:4
                m(i,j)=100*i+j;
            end
        end
        disp(m)
            
    case 6
        %% Example 6
        x=randn;
        couter=1;
        while x<5
            couter=couter+1;
            x=randn;
        end
        disp(couter)
                
    case 7
        %% Example 7
        counter=0;
        for i=1:1000000
            x=2*rand-1;
            y=2*rand-1;
            if x^2+y^2<1
                counter=counter+1;
            end
        end
        disp(4*counter/1000000)
            
    case 8
        %% Example 8
        x=[];y=[];
        for j=1:1000
            for i=1:sqrt(1+2*j)
            if i^2==1+2*j
                x=[x,i];y=[y,j];
            end
            end
        end
        M=[x,y];
        M=reshape(M,length(M)/2,2)
            
    case 9
        %% Example 9
        str=input('Please input a string and I will output it in a reversed order:','s')
        tmpstr=str;
        for i=0:length(str)-1
            str(length(str)-i)=tmpstr(i+1);
        end
        tmpstr 
        
    case 10
        %% Example 10
        money=10000;
        sum_money=money;
        interest_rate=0.0425;
        year=1;
        while (1+interest_rate)*sum_money<2*money
            year=year+1;
            sum_money=(1 + interest_rate) * sum_money;
        end
        year
    case 11
        %% Example 11
        arr=input('Please input some numbers and I will sort them by bubble_sort(pay attention to the format:[numbers]):');
        arr=bubble_sort(arr)
end