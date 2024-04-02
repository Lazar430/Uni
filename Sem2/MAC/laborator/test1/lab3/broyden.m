function x=conjgrad(A,b,x0,n)

d0 = b - A * x0;
r0 = b - A * x0;    

for k = 0 : n-1
    if(r0 == 0)
        break;
    end

    alfa = (r0' * r0) / (d0' * A * d0);
    x1 = x0 + alfa * d0;
    r1 = r0 - alfa * A * d0;
    beta = (r1' * r1) / (r0' * r0);
    d1 = r1 + beta * d0;

    x0 = x1;
    d0 = d1;
    r0 = r1;
end

x = x1;