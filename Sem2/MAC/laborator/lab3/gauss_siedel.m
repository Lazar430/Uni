function x = jacobi(A,b,x0,k)
  D = diag(diag(A));
L = tril(A) - D;
U = triu(A) - D;
x = x0;
for j = 1 : k
	x = inv(D + L) * (b - U*x);
end
