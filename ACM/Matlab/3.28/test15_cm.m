function r=test15_cm
r=[];
for i=0:9
    for j=0:9
        for k=0:3
            if(fix((1000*i+100*j+10*k+8)/2)==(1000*i+100*j+10*k+8)/2)&&(fix((1000*i+100*j+10*k+8)/3)==(1000*i+100*j+10*k+8)/3)
                r=[r,1000*i+100*j+10*k+8];
            end
        end
    end
end
end