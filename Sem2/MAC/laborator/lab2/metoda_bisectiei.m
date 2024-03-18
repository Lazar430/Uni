function c = metoda_bisectiei(f,a,b,toleranta)

f_a = f(a);
f_b = f(b);

if sign(f_a) * sign(f_b) >= 0
error('conditia sign(f_a)sign(f_b) < 0 nu e satisfacuta!s')
end
while (b - a) / 2 >toleranta
c= ( a + b) / 2;
f_c = f(c);
if f_c == 0
break;
end
if sign(f_c) * sign(f_a) < 0
b = c;
f_b = f_c;
else
a = c;
f_a = f_c;
end
end
c = (a + b) / 2;
