F = @(x) [x(1)^2 + 4 * x(2)^2 - 4; 4 * x(1)^2 + x(2)^2 - 4];
DF = @(x) [2*x(1) 8*x(2); 8*x(1)  2*x(2)];
x0 = [1; 1];

format long
ans1 = newton(F, DF, x0, 5)