nod1 = {"valoare": 1, "stanga": None, "dreapta": None}
nod7 = {"valoare": 7, "stanga": None, "dreapta": None}
nod3 = {"valoare": 3, "stanga": nod1, "dreapta": nod7}
nod4 = {"valoare": 4, "stanga": nod7, "dreapta": nod1}
nod2 = {"valoare": 2, "stanga": None, "dreapta": nod3}
nod8 = {"valoare": 8, "stanga": nod4, "dreapta": nod2}
nod6 = {"valoare": 6, "stanga": nod3, "dreapta": nod8}

def parcurgere_arbore_binar_in_preordine(arbore_binar):
    if(arbore_binar == None):
        return []
    else:
        return [arbore_binar["valoare"]] + parcurgere_arbore_binar_in_preordine(arbore_binar["stanga"]) + parcurgere_arbore_binar_in_preordine(arbore_binar["dreapta"])

def interschimbare_arbore_binar(arbore_binar):
    if(arbore_binar is not None):
        copie_arbore = arbore_binar["stanga"]
        arbore_binar["stanga"] = arbore_binar["dreapta"]
        arbore_binar["dreapta"] = copie_arbore
        interschimbare_arbore_binar(arbore_binar["stanga"])
        interschimbare_arbore_binar(arbore_binar["dreapta"])
        return arbore_binar

print(parcurgere_arbore_binar_in_preordine(nod6))
print(parcurgere_arbore_binar_in_preordine(interschimbare_arbore_binar(nod6)))
