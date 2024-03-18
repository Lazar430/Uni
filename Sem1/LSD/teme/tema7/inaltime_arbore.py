import functools

nod7 = {"valoare": 7, "stanga": None , "dreapta": None}
nod6 = {"valoare": 6, "stanga": None , "dreapta": None}
nod5 = {"valoare": 5, "stanga": None , "dreapta": None}
nod4 = {"valoare": 4, "stanga": None , "dreapta": nod6}
nod2 = {"valoare": 2, "stanga": nod4 , "dreapta": nod5}
nod1 = {"valoare": 1, "stanga": nod7 , "dreapta": nod2}
arbore_binar = nod1

arbore_oarecare = {
    "valoare": 1,
    "copii": [
        {"valoare": 7, "copii": [{
            "valoare": 10, "copii": [{
                "valoare": 11, "copii": [{
                    "valoare": 12, "copii": [{
                        "valoare": 13, "copii": []
                    }]
                }]
            }]
        }]},
        {"valoare": 3, "copii": []},
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

'''

def inaltime_arbore_binar(arbore_binar):
    if(arbore_binar["stanga"] is None and arbore_binar["dreapta"] is None):
        return 1
    
    inaltime_arbore_stanga = 0
    inaltime_arbore_dreapta = 0

    if(arbore_binar["stanga"] is not None):
        inaltime_arbore_stanga = 1 + inaltime_arbore_binar(arbore_binar["stanga"])
    if(arbore_binar["dreapta"] is not None):
        inaltime_arbore_dreapta = 1 + inaltime_arbore_binar(arbore_binar["dreapta"])

    return max(inaltime_arbore_stanga, inaltime_arbore_dreapta)

'''

def inaltime_arbore_binar(arbore_binar, inaltime_locala = 1, inaltime = 0):
    if(arbore_binar["stanga"] is None and arbore_binar["dreapta"] is None):
        return max(inaltime_locala, inaltime)
    else:
        if(arbore_binar["stanga"] is not None):
            inaltime = inaltime_arbore_binar(arbore_binar["stanga"], inaltime_locala + 1, inaltime)
        if(arbore_binar["dreapta"] is not None):
            inaltime = inaltime_arbore_binar(arbore_binar["dreapta"], inaltime_locala + 1, inaltime)
    return inaltime

def inaltime_arbore_oarecare(arbore, inaltime_locala = 1, inaltime = 0):
    if(arbore["copii"] is []):
        inaltime = max(inaltime_locala, inaltime)
    else:
        def inaltime_subarbore(acc, curr):
            if(curr is not []):
                acc = inaltime_arbore_oarecare(curr, inaltime_locala + 1, acc)
            return acc
        inaltime = max(functools.reduce(inaltime_subarbore, arbore["copii"], inaltime_locala), inaltime)
    return inaltime

print(inaltime_arbore_binar(arbore_binar))
print(inaltime_arbore_oarecare(arbore_oarecare))
