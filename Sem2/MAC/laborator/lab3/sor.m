function x = sor(A,b,x0,omega,k)

D = diag(diag(A));
L = tril(A) - D;
U = triu(A) - D;
x = x0;
for j = 1 : k
	x = inv(omega*L + D)*((1-omega)*D*x -omega * U * x) + omega * inv(D + omega * L) * b;
end