function dfun=vdpol(t,x)
            dfun=[x(2);20*(1-x(1)*x(1))*x(2)+0.5*x(1)];
end