x0=[1994;1995;1996;1997;1998;1999;2000;2001;2002;2003]-1994;
y0=[67.052;68.008;69.803;72.024;73.400;72.063;74.669;74.487;74.065;76.777];


A1 = zeros(length(y0), 2);
for i = 1:length(y0)
    for j = 1:2
        if(j==1)
            A1(i,j) = 1;
        else
            A1(i,j) = x0(i);
        end
    end
end

c1 = inv(A1' * A1) * (A1' * y0)
aprox1 = c1(1) + c1(2) * 24
r1 = y0 - A1 * c1;
REMP1 = norm(r1) / sqrt(length(y0))


A2 = zeros(length(y0), 3);
for i = 1:length(y0)
    for j = 1:3
        if(j==1)
            A2(i,j) = 1;
        end
        if(j==2)
            A2(i,j) = x0(i);
        end
        if(j==3)
            A2(i,j) = x0(i) * x0(i);
        end
    end
end

c2 = inv(A2' * A2) * (A2' * y0)
aprox2 = c2(1) + c2(2) * 24 + c2(3) * 24 * 24
r2 = y0 - A2 * c2;
REMP2 = norm(r2) / sqrt(length(y0))


A3 = zeros(length(y0), 4);
for i = 1:length(y0)
    for j = 1:4
        if(j==1)
            A3(i,j) = 1;
        end
        if(j==2)
            A3(i,j) = x0(i);
        end
        if(j==3)
            A3(i,j) = x0(i) * x0(i);
        end
        if(j==4)
            A3(i,j) = x0(i) * x0(i) * x0(i);
        end
    end
end

c3 = inv(A3' * A3) * (A3' * y0)
aprox3 = c3(1) + c3(2) * 24 + c3(3) * 24 * 24 + c3(4) * 24 * 24 * 24
r3 = y0 - A3 * c3;
REMP3 = norm(r3) / sqrt(length(y0))