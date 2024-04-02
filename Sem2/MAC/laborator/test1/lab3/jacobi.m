function x = jacobi(a, b, x0, k)

D = diag(diag(a));
L = tril(a) - D;
U = triu(a) - D;

for i = 1:k
    x = inv(D) * (b - (L + U) * x0);
    x0 = x;
end