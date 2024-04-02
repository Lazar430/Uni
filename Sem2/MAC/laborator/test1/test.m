format long;

f = @(x) x^3 - 2 * x - 2;
df = @(x) 3 * x^2 - 2;
%fplot(f);
%grid on;

%bisection(f, -2, -1.5, 0.000001)
%bisection(f, -1, 1, 0.000001)
%bisection(f, 1, 2, 0.000001)

%secant(f, -2, -1.8, 0.000001)

newton(f, df, 1, 10)