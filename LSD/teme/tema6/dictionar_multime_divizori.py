import functools

def multime_divizori(numar, divizor = 1, multimea_divizorilor = None):
    if(multimea_divizorilor == None):
        multimea_divizorilor = set()
    if(divizor * divizor > numar):
        return multimea_divizorilor
    else:
        if(numar % divizor == 0):
            multimea_divizorilor.add(divizor)
            multimea_divizorilor.add(numar // divizor)
        return multime_divizori(numar, divizor + 1, multimea_divizorilor)

def adaugare_dictionar(dictionar, item):
    dictionar[item[0]] = item[1]
    return dictionar
    
def dictionar_multime_divizori(lista):
    return functools.reduce(lambda acc, curr: adaugare_dictionar(acc, (curr, multime_divizori(curr))), lista, {})
    
print(dictionar_multime_divizori([12, 13, 14, 15, 16]))
            
