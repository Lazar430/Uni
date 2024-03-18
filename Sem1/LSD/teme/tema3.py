def interval(valoare_minima, valoare_maxima):
    if(valoare_minima > valoare_maxima):
        return None
    else:
        print(valoare_minima)
        valoare_minima += 1
        interval(valoare_minima, valoare_maxima)

def aparitie(n, cifra):
    if n == 0:
        print("Cifra " + str(cifra) + " nu apare in numarul " + str(aparitie.numar))
        return None
    else:
        if(n % 10 == cifra):
            print("Cifra " + str(cifra) + " apare in numarul " + str(aparitie.numar))
            return None
        aparitie(int(n / 10), cifra)


def numar_aparitii(n, cifra):
    if n == 0:
        return 0
    else:
        return (n % 10 == cifra) + numar_aparitii(int(n / 10), cifra)

def conversie_zecimal_binar(n):
    if n == 0:
        return ""
    else:
        return conversie_zecimal_binar(int(n / 2)) + str(n % 2)

numar = 1011489193
cifra = 1
aparitie.numar = numar
print("Cifra " + str(cifra) + " apare de " + str(numar_aparitii(numar, cifra)) + " ori in numarul " + str(numar))

