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

def lista_noduri_monoparentale(arbore_binar, lista_noduri = []):
    if(arbore_binar["stanga"] is None and arbore_binar["dreapta"] is None):
        return lista_noduri
    if(arbore_binar["stanga"] is not None and arbore_binar["dreapta"] is None):
        lista_noduri += [arbore_binar["valoare"]]
        lista_noduri = lista_noduri_monoparentale(arbore_binar["stanga"], lista_noduri)
    if(arbore_binar["stanga"] is None and arbore_binar["dreapta"] is not None):
        lista_noduri += [arbore_binar["valoare"]]
        lista_noduri = lista_noduri_monoparentale(arbore_binar["dreapta"], lista_noduri)
    if(arbore_binar["stanga"] is not None and arbore_binar["dreapta"] is not None):
        lista_noduri = lista_noduri_monoparentale(arbore_binar["stanga"], lista_noduri)
        lista_noduri = lista_noduri_monoparentale(arbore_binar["dreapta"], lista_noduri)

    return lista_noduri
    

print(lista_noduri_monoparentale(arbore_binar))
