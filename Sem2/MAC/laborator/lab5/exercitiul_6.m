t0=[0;1/6;1/3;1/2;2/3;5/6];
y0=[0;2;0;-1;1;1];

A3 = [ones(length(t0), 1), cos(2 * pi * t0)];
A4 = [ones(length(t0), 1), cos(2 * pi * t0), sin(2 * pi * x0), cos(4 * pi * x0)];

c = (A3' * A3) \ (A3' * y0)

r = y0 - A3*c;
REMP = norm(r) / sqrt(length(r))