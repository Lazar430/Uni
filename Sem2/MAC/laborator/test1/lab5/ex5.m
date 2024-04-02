t0=([1;2;3;4;5;6;7;8;9;10;11;12]-1)/12;
y0=[6.224;6.665;6.241;5.302;5.073;5.127;4.994;5.012;5.108;5.377;5.510;6.372];

A = zeros(length(y0), 4);
for i = 1:length(y0)
    for j = 1:4
        if(j==1)
            A(i,j) = 1;
        end
        if(j==2)
            A(i,j) = cos(2*pi*t0(i));
        end
        if(j==3)
            A(i,j) = sin(2*pi*t0(i));
        end
        if(j==4)
            A(i,j) = cos(4*pi*t0(i));
        end
    end
end

c = inv(A' * A) * (A' * y0)
r = y0 - A * c;
REMP = norm(r) / sqrt(length(y0))