function x = grad_conj(A, b, x0, k)

x = x0;
d = b - A * x;

r = d;

for i = 0 : k
    
    if r == 0 
        break;
    end

    alpha = (r' * r) \ (d' * A * d);

    x = x + alpha * d;

    r_nou = r - alpha * A * d;

    beta = (r_nou' * r_nou) \ (r' * r);

    d = r_nou + beta * d;

    r = r_nou;

end