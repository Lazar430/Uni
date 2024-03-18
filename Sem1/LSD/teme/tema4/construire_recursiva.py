import math

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

def construire_recursiva_numar(lista_cifre, conditie):
    if(len(lista_cifre) == 1):
        if conditie(lista_cifre[0]):
           return lista_cifre[0]
        else:
           return 0
    else:
        element_curent = lista_cifre.pop()
        if conditie(element_curent):
            return element_curent + 10 * construire_recursiva_numar(lista_cifre, conditie)
        else:
            return construire_recursiva_numar(lista_cifre, conditie)

lista_cifre = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print(construire_recursiva_numar(lista_cifre, este_prim))
