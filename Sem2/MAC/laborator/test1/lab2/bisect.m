function result = bisect(f, a, b, tol)

while (a + b)/2 > tol
    c = (a + b)/2;
    if(f(c) == 0) 
        break;
    end
    if(f(a) * f(c) < 0)
        b = c;
    else
        a = c;
    end
end

result = (a + b)/2;