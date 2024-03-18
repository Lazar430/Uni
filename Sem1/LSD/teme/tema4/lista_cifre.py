def mai_mic_ca_7(numar):
    return int(numar) < 7

def filtrare_cifre(numar, conditie):
    return [eval(i) for i in list(filter(conditie, str(numar)))]

print(filtrare_cifre(132943987128, mai_mic_ca_7))
