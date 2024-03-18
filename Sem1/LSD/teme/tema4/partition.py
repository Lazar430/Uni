def partition(conditie, lista, lista1 = [], lista2 = []):
    if len(lista) != 0:
        if conditie(lista[0]):
            lista1 += [lista[0]]
        else:
            lista2 += [lista[0]]

        return partition(conditie, lista[1:])
    else:
        return (lista1, lista2)

print(partition(lambda x : x >= 5, [4, 6, 7, 5, 4, 8, 9]))
