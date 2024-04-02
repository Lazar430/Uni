function xc=fpi(g,x0,k)
x = zeros(1, k + 1);
x(1)=x0;
for i=1:k
x(i+1)=g(x(i));
end
xc=x(k+1);
