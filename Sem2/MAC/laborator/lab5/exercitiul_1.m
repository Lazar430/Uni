A=[3 -1 2;4 1 0;-3 2 1;1 1 5;-2 0 3];
b=[10;10;-5;15;0];
x = (A' * A) \ (A' * b);
r = b - Ax;
REMP = norm(r) / sqrt(length(r));