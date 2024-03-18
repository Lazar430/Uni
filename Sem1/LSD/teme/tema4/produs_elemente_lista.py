import functools

lista_numere = [1, 2, 3, 4, 5]

produs = functools.reduce(lambda acc, curr: acc * curr, lista_numere, 1)

print(produs)
