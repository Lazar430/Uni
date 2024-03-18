def dictionar_siruri(dictionar, lista, multime_valori = None):
    if(multime_valori == None):
        multime_valori = set()
    if(lista == []):
        return multime_valori
    if(lista[0] in dictionar):
        multime_valori.add(dictionar[lista[0]])
    return dictionar_siruri(dictionar, lista[1:], multime_valori)

print(dictionar_siruri({'aa': 5, 'bb': 7, 'ca': 6}, ['aa', 'bb', 'c']))
