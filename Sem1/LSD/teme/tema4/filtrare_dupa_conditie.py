def este_par(numar):
    return numar % 2 == 0

def elemente_pare(lista_numere, ordine_inversa = False):
    ret = list(filter(este_par, lista_numere))
    if ordine_inversa == True:
        ret.reverse()
    return ret


lista_numere = [2198, 491, 19, 342, 1815, 247, 48, 922]

print(elemente_pare(lista_numere, True))
