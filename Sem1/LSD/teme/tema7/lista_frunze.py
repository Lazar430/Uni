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
    "valoare": 1,
    "copii": [
        {"valoare": 7, "copii": []},
        {"valoare": 3, "copii": []},
        {"valoare": 2, "copii": [
            {"valoare":4, "copii": [
                {"valoare": 6, "copii": []}
            ]},
            {"valoare": 5, "copii": []}
        ]},
    ]
}

def lista_frunze_arbore_binar(arbore_binar, lista_frunze = []):
    if(arbore_binar["stanga"] is None and arbore_binar["dreapta"] is None):
        lista_frunze += [arbore_binar["valoare"]]
    else:
        if(arbore_binar["stanga"] is not None):
            lista_frunze = lista_frunze_arbore_binar(arbore_binar["stanga"], lista_frunze)
        if(arbore_binar["dreapta"] is not None):
            lista_frunze = lista_frunze_arbore_binar(arbore_binar["dreapta"], lista_frunze)
    return lista_frunze

def lista_frunze_arbore_oarecare(arbore, lista_frunze = []):
    if(arbore["copii"] == []):
        lista_frunze += [arbore["valoare"]]
    else:
        def exista_copii(acc, curr):
            if(curr is not []):
                acc = lista_frunze_arbore_oarecare(curr, acc)
            return acc
        return functools.reduce(exista_copii, arbore["copii"], lista_frunze)
    return lista_frunze

print(lista_frunze_arbore_binar(arbore_binar))
print(lista_frunze_arbore_oarecare(arbore_oarecare))
