def liste_cifre(lista):
    return [ list(map(int, list(filter(lambda x : int(x) % 2 == 0, str(numar))))) for numar in lista ]

print(liste_cifre([24, 6831, 99, 10, 102]))
