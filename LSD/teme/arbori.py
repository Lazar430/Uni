nod1 = {"valoare": 1, "stanga": None, "dreapta": None}
nod3 = {"valoare": 3, "stanga": None, "dreapta": None}
nod2 = {"valoare": 2, "stanga": nod1, "dreapta": nod3}
nod7 = {"valoare": 7, "stanga": None, "dreapta": None}
nod4 = {"valoare": 4, "stanga": nod2, "dreapta": nod7}
radacina = nod4

nod5 = {"valoare": 5, "stanga": None, "dreapta": None}
nod6 = {"valoare": 6, "stanga": None, "dreapta": None}
nod8 = {"valoare": 8, "stanga": None, "dreapta": None}

def inserare_nod_in_arbore_binar(arbore_binar, nod_de_inserat):
    if(nod_de_inserat["valoare"] < arbore_binar["valoare"]):
        if(arbore_binar["stanga"] is None):
            arbore_binar["stanga"] = nod_de_inserat
        else:
            inserare_nod_in_arbore_binar(arbore_binar["stanga"], nod_de_inserat)
    if(nod_de_inserat["valoare"] > arbore_binar["valoare"]):
        if(arbore_binar["dreapta"] is None):
            arbore_binar["dreapta"] = nod_de_inserat
        else:
            inserare_nod_in_arbore_binar(arbore_binar["dreapta"], nod_de_inserat)

def parcurgere_arbore_binar_in_preordine(arbore_binar):
    if(arbore_binar == None):
        return []
    else:
        return [arbore_binar["valoare"]] + parcurgere_arbore_binar_in_preordine(arbore_binar["stanga"]) + parcurgere_arbore_binar_in_preordine(arbore_binar["dreapta"])

inserare_nod_in_arbore_binar(radacina, nod5)
inserare_nod_in_arbore_binar(radacina, nod6)
inserare_nod_in_arbore_binar(radacina, nod8)
print(parcurgere_arbore_binar_in_preordine(radacina))
