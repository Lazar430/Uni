def arie_dreptunghi(lungime, latime):
    return lungime * latime

def volum_paralelipiped(lungime, latime, inaltime):
    return arie_dreptunghi(lungime, latime) * inaltime

def eliminare_caracter(caracter, *siruri):
    sir_concatenat = list(range(len(siruri)))
    index = 0
    for sir in siruri:
        sir_concatenat[index] = sir.replace(caracter, "")
        index += 1

    return ' '.join(sir_concatenat)

def suma_minima(numar_calatorii):
    pret_calatorie = 2.75
    pret_brut = pret_calatorie * numar_calatorii

    if numar_calatorii == 1:
        return pret_brut
    else:
        reducere = round(5 * pret_brut)
        reducere = (reducere - reducere % 5) / 100
        pret_redus = pret_brut - reducere
        return pret_redus
