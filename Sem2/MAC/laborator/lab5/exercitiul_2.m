x0=[-3;-1;0;1;3];
y0=[3;2;1;-1;-4];

A = [x0, ones(length(x0), 1)];

c = (A' * A) \ (A' * y0)

r = y0 - A*c;
REMP = norm(r) / sqrt(length(r))

t = -5:0.01:5;
y = c(2) + c(1) * t;
plot(x0, y0, 'p',t, y)