function arr = bubble_sort(x)
[a,b]=size(x);
key=1;
if a ~= 1 && b ~= 1
    key=0;
    disp('This is not a n¡Á1 or 1¡Án arr!')
end
if key==1
    for i=1:length(x)
        for j=1:length(x)-i
            if x(j)>x(j+1)
                temp=x(j);
                x(j)=x(j+1);
                x(j+1)=temp;
            end
        end
    end
end
arr=x;
end

