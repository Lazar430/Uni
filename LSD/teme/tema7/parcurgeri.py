import functools

arbore_binar = {
    "valoare" : 1, "dreapta" : {
        "valoare" : 2, "stanga" : {
            "valoare" : 4, "stanga" : None, "dreapta" : {
                "valoare" : 6, "stanga" : None, "dreapta" : None
            }   
        }, "dreapta" : {
            "valoare" : 5, "stanga" : None, "dreapta" : None
        }
    }, "stanga" : {
        "valoare" : 7, "stanga" : {
            "valoare" : 8, "stanga" : {
                "valoare" : 13, "stanga" : None, "dreapta" : {
                    "valoare" : 11, "stanga" : None, "dreapta" : None
                }
            }, "dreapta" : {
                "valoare" : 14, "stanga" : None, "dreapta" : None
            }
        }, "dreapta" : {
            "valoare" : 5, "stanga" : None, "dreapta" : None
        }
    }
}

arbore_oarecare = {
    "valoare" : 1, "copii" : [ {
        "valoare" : 2, "copii" : [ { "valoare" : 5, "copii" : []  }, { "valoare" : 6, "copii" : []  } ]
    }, { "valoare" : 3, "copii" : []  }, { "valoare" : 4, "copii" : [ { "valoare" : 7, "copii" : [
        { "valoare" : 11, "copii" : []  }, { "valoare" : 12, "copii" : []  }
    ]  }, { "valoare" : 8, "copii" : []  }, { "valoare" : 9, "copii" : [
        { "valoare" : 13, "copii" : []  }, { "valoare" : 14, "copii" : []  }, { "valoare" : 15, "copii" : [
            {"valoare" : 16, "copii" : [] }, { "valoare" : 17, "copii" : []  }
        ]  }
    ]  }, { "valoare" : 10, "copii" : []  } ] } ]
}

def parcurgere_arbore_binar_in_preordine(arbore_binar):
    if(arbore_binar == None):
        return []
    else:
        return [arbore_binar["valoare"]] + parcurgere_arbore_binar_in_preordine(arbore_binar["stanga"]) + parcurgere_arbore_binar_in_preordine(arbore_binar["dreapta"])

def parcurgere_arbore_binar_in_inordine(arbore_binar):
    if(arbore_binar == None):
        return []
    else:
        return  parcurgere_arbore_binar_in_inordine(arbore_binar["stanga"]) + [arbore_binar["valoare"]] + parcurgere_arbore_binar_in_inordine(arbore_binar["dreapta"])

def parcurgere_arbore_binar_in_postordine(arbore_binar):
    if(arbore_binar == None):
        return []
    else:
        return  parcurgere_arbore_binar_in_postordine(arbore_binar["stanga"]) + parcurgere_arbore_binar_in_postordine(arbore_binar["dreapta"]) + [arbore_binar["valoare"]]

def parcurgere_arbore_oarecare_in_preordine(arbore, lista_noduri_parcurse = []):
    def parcurgere_subarbore_in_preordine(acc, curr):
        if(curr["copii"] is not []):
            acc = parcurgere_arbore_oarecare_in_preordine(curr, acc)
        return acc
    lista_noduri_parcurse += [arbore["valoare"]]
    lista_noduri_parcurse = functools.reduce(parcurgere_subarbore_in_preordine, arbore["copii"], lista_noduri_parcurse)

    return lista_noduri_parcurse


print(parcurgere_arbore_binar_in_preordine(arbore_binar))
print(parcurgere_arbore_binar_in_inordine(arbore_binar))
print(parcurgere_arbore_binar_in_postordine(arbore_binar))

print()

print(parcurgere_arbore_oarecare_in_preordine(arbore_oarecare))
