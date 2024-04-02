t0=[0;1/6;1/3;1/2;2/3;5/6];
y0=[0;2;0;-1;1;1];

A1 = zeros(length(y0), 3);
for i = 1:length(y0)
    for j = 1:3
        if(j==1)
            A1(i,j) = 1;
        end
        if(j==2)
            A1(i,j) = cos(2*pi*t0(i));
        end
        if(j==3)
            A1(i,j) = sin(2*pi*t0(i));
        end
    end
end

c1 = inv(A1' * A1) * (A1' * y0)
r1 = y0 - A1 * c1;
n1 = norm(r1)


A2 = zeros(length(y0), 4);
for i = 1:length(y0)
    for j = 1:4
        if(j==1)
            A2(i,j) = 1;
        end
        if(j==2)
            A2(i,j) = cos(2*pi*t0(i));
        end
        if(j==3)
            A2(i,j) = sin(2*pi*t0(i));
        end
        if(j==4)
            A2(i,j) = cos(4*pi*t0(i));
        end
    end
end

c2 = inv(A2' * A2) * (A2' * y0)
r2 = y0 - A2 * c2;
n2 = norm(r2)