function result = iteratie_pct_fix(f, x0, k)

for i=1:k
    result = f(x0);
    x0 = result;
end