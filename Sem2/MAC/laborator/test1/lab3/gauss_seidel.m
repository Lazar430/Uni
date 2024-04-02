function x = gauss_seidel(a, b, x0, k)

D = diag(diag(a));
L = tril(a) - D;
U = triu(a) - D;

for i = 1:k
    x = inv(L + D) * (b - U * x0);
    x0 = x;
end