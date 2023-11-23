nod1 = {"valoare": 1, "stanga": None, "dreapta": None}
nod7 = {"valoare": 7, "stanga": None, "dreapta": None}
nod3 = {"valoare": 3, "stanga": nod1, "dreapta": nod7}
nod4 = {"valoare": 4, "stanga": nod7, "dreapta": nod1}
nod2 = {"valoare": 2, "stanga": None, "dreapta": nod3}
nod8 = {"valoare": 8, "stanga": nod4, "dreapta": nod2}
nod6 = {"valoare": 6, "stanga": nod3, "dreapta": nod8}

arbore_binar = { "valoare" : 2, "stanga":
                     {
                        "valoare": 7, "stanga": None, "dreapta":
                             {
                                  "valoare": 6, "stanga":
                                      {
                                         "valoare": 5, "stanga": None, "dreapta": None
                                      }, "dreapta":
                                      {
                                          "valoare":11, "stanga": None, "dreapta": None
                              },
                      },
                      }, "dreapta":
                      {
                           "valoare": 4, "stanga": None, "dreapta": None
                       }
        }

def afisare_indentata(arbore_binar, spatii = "  "):
    print(spatii + str(arbore_binar["valoare"]))
    if(arbore_binar["stanga"] is not None):
        afisare_indentata(arbore_binar["stanga"], spatii + "  ")
    if(arbore_binar["dreapta"] is not None):
        afisare_indentata(arbore_binar["dreapta"], spatii + "  ")

afisare_indentata(arbore_binar)
