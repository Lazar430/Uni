A = [4 2 3 0;-2 3 -1 1;1 3 -4 2;1 0 1 -1;3 1 3 -2];
y = [10;0;2;0;5];

[Q, R] = qr(A);

d = Q \ y;
c = R \ d