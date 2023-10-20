import math
import functools

def este_prim(numar):
    if numar == 0 or numar == 1:
        return False
    elif numar % 2 == 0 and numar != 2:
        return False
    else:
        for i in range(3, int(math.sqrt(numar)) + 1, 2):
            if (numar % i == 0):
                return False
    return True

def construire_functionala_numar(lista_cifre, conditie):
    return functools.reduce(lambda acc, curr: acc * 10 + curr, list(filter(conditie, lista_cifre)), 0)

lista_cifre = [1, 2, 3, 4, 5, 6, 7, 8, 9]

print(construire_functionala_numar(lista_cifre, este_prim))
