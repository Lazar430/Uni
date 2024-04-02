A = [1 -3; 1 -1; 1 0; 1 1; 1 3];
b = [3; 2; 1; -1; -4];

c = inv(A' * A) * (A' * b)

r = b - A * c;
n = length(b);
REMP = norm(r) / sqrt(n)