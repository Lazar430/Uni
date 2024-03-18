lista_siruri_caractere = ["daji2", "19", "os", "flkerm34", "d", "", "vjd9cm"]

lista_siruri_caractere_redusa = list(filter(lambda c : len(c) < 3, lista_siruri_caractere))

print(lista_siruri_caractere_redusa)
