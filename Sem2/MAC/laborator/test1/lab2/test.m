format long;

f = @(x) 2 * x^3 - 6 * x - 1;
fplot(f);
grid on;

bisect(f, -2, -1.5, 0.0000001)