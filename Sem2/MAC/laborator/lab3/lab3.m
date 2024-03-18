format long

A = [3, -1, 1; 1, -8, -2; 1, 1, 5];

b = [-2; 1; 4];

x0 = zeros(3, 1);

x = grad_conj(A, b, x0, 10)