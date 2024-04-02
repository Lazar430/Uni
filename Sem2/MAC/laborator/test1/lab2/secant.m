function result = secant(f, x0, x1, k)

for i = 1:k
    result = x1 - (f(x1) * (x1 - x0))/(f(x1) - f(x0));
    x0 = x1;
    x1 = result;
end