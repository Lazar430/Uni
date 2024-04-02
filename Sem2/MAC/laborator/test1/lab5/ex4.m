a = -1;
b = 1;
k = 6;

x_nodes = cebisev(a, b, k);
y_nodes = exp(x_nodes);

c = newtondd(x_nodes, y_nodes, k-1)
