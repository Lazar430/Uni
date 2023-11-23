import functools

def extragere_sir(lista):
    return functools.reduce(lambda acc, curr: acc + curr, lista, "")

def dictionar_numar_aparitii(sir, dictionar = {}):
    if(sir == ""):
        return dictionar
    if(sir[0] in dictionar):
        dictionar[sir[0]] += 1
    else:
        dictionar[sir[0]] = 1
    return dictionar_numar_aparitii(sir[1:], dictionar)

def numar_aparitii(lista):
    sir = extragere_sir(lista)
    return dictionar_numar_aparitii(sir)

print(numar_aparitii(["aaa", "bbb", "aabbb"]))
