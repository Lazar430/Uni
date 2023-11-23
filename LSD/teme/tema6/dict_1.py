import functools

def adaugare(dictionar, pereche):
    dictionar[pereche[0]] = pereche[1]
    return dictionar

def creare_dictionar(lista):
    return functools.reduce(lambda acc, curr: adaugare(acc, curr), lista, {})

print(creare_dictionar([('a',7), ('b',5), ('c',2), ('a',3), ('b',3)]))
