function x = Cebisev(a, b, k)
  for i = 1 : k
      x(i) = (b + a) /  2 + ((b - a) / 2) * cos( ((2 * i - 1) * pi) / 2 * k);
  end