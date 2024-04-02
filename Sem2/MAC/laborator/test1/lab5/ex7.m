t0=[-2;0;1;2];
y0=[1;2;2;5];

n = length(y0);

b = zeros(n, 1);
for i = 1:n
    b(i) = log(y0(i));
end

A = zeros(n, 2);
for i = 1:n
    for j = 1:2
        if(j==1)
            A(i, j) = 1;
        else
            A(i, j) = t0(i);
        end
    end
end

c = inv(A' * A) * (A' * b)
r = y0 - exp(c(1)) * exp(c(2) * t0);
n = norm(r)
