function x = newton(F,DF,x0,k)

for i = 0:k
    x1 = x0 - DF(x0) \ F(x0);
    x0 = x1;
end

x = x0;

