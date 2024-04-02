function [a,x] = gauss(a, b)

n = length(a);

for j = 1:n-1
    if(a(j,j) == 0) 
        break;
    end
    for i = j+1:n
        caca = a(i,j)/a(j,j);
        for k = j:n    
            a(i,k) = a(i,k) - caca * a(j,k);
        end
        b(i) = b(i) - caca * b(j);
    end
end

for i = n:-1:1
    for j = i+1:n
        b(i) = b(i) - a(i,j) * x(j);
    end
    x(i) = b(i) / a(i,i);
end


