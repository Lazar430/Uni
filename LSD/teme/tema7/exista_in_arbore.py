import functools

nod7 = {"valoare": 7, "stanga": None , "dreapta": None}
nod6 = {"valoare": 1, "stanga": None , "dreapta": None}
nod5 = {"valoare": 5, "stanga": None , "dreapta": None}
nod4 = {"valoare": 6, "stanga": None , "dreapta": nod6}
nod2 = {"valoare": 13, "stanga": nod4 , "dreapta": nod5}
nod1 = {"valoare": 1, "stanga": nod7 , "dreapta": nod2}
arbore_binar = nod1

arbore_oarecare = {
    "valoare": 1,
    "copii": [
        {"valoare": 7, "copii": [{
            "valoare": 10, "copii": [{
                "valoare": 11, "copii": [{
                    "valoare": 12, "copii": [{
                        "valoare": 14, "copii": []
                    }]
                }]
            }]
        }]},
        {"valoare": 9, "copii": []},
        {"valoare": 2, "copii": [
            {"valoare":4, "copii": [
                {"valoare": 6, "copii": []}
            ]},
            {"valoare": 5, "copii": [{
                "valoare": 8, "copii": [{
                    "valoare": 9, "copii": []
                }]
            }]}
        ]},
    ]
}

def exista_in_arbore_binar(arbore_binar, conditie):
    if(arbore_binar["stanga"] is None and arbore_binar["dreapta"] is None):
        return conditie(arbore_binar["valoare"])
    if(arbore_binar["stanga"] is not None and arbore_binar["dreapta"] is None):
        return conditie(arbore_binar["valoare"]) or exista_in_arbore_binar(arbore_binar["stanga"], conditie)
    if(arbore_binar["stanga"] is None and arbore_binar["dreapta"] is not None):
        return conditie(arbore_binar["valoare"]) or exista_in_arbore_binar(arbore_binar["dreapta"], conditie)
    if(arbore_binar["stanga"] is not None and arbore_binar["dreapta"] is not None):
        return conditie(arbore_binar["valoare"]) or exista_in_arbore_binar(arbore_binar["stanga"], conditie) or exista_in_arbore_binar(arbore_binar["dreapta"], conditie)

def exista_in_arbore_oarecare(arbore, conditie):
    if(arbore["copii"] is []):
        return conditie(arbore["valoare"])
    else:
        def exista_in_subarbore(acc, curr):
            if(curr is not []):
                return acc or exista_in_arbore_oarecare(curr, conditie)
            else:
                return acc 
        return conditie(arbore["valoare"]) or functools.reduce(exista_in_subarbore, arbore["copii"], False)
    
print(exista_in_arbore_binar(arbore_binar, lambda x : x % 2 == 0))
print(exista_in_arbore_oarecare(arbore_oarecare, lambda x : x % 10 == 3))
