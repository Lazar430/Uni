t0=[-2;0;1;2];
y0=[1;2;2;5];

A = [ones(length(t0), 1), t0];
c = (A' * A) \ (A' * log(y0));
r = y0 - exp(c(1)) * exp(c(2) * t0);