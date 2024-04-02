function coeff = splinecoeff(x, y)

n = length(x);
A = zeros(n, n);
r = zeros(n,1);

for i = 1 : (n-1)
    dx(i) = x(i+1) - x(i);
    dy(i) = y(i+1) - y(i);
end

A(1, 1) = 1;
A(n, n)= 1;

for i = 2 : n-1
    A(i, i - 1) = dx(i - 1);
    A(i, i) = 2 * (dx(i - 1) + dx(i));
    A(i, i + 1) = dx(i);
    r(i) = 3 * ((dy(i)/dx(i)) - (dy(i - 1)/dx(i - 1)));
end

c = A \ r;

for i = 1 : n-1
    d(i) = (c(i+1) - c(i)) / (3 * dx(i));
    b(i) = (dy(i)/dx(i)) - (dx(i) * (2 * c(i) + c(i + 1))) / 3;
end

for i = 1 : n-1
    coeff(i,1) = b(i);
    coeff(i,2) = c(i);
    coeff(i,3) = d(i);
end
