arbore_binar_de_cautare = { "valoare" : 4, "stanga":
                             {"valoare": 2, "stanga": {"valoare": 1, "stanga": None, "dreapta": None}, "dreapta": {"valoare": 3, "stanga": None, "dreapta": None},
                             }, "dreapta":
                             {"valoare": 7, "stanga": None, "dreapta": None}
                          }

arbore_binar_de_necautare = { "valoare" : 2, "stanga":
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

def este_arbore_binar_de_cautare(arbore_binar):
    if(arbore_binar["stanga"] is None and arbore_binar["dreapta"] is None):
        return True
    if(arbore_binar["stanga"] is not None and arbore_binar["dreapta"] is None):
        return arbore_binar["valoare"] > arbore_binar["stanga"]["valoare"] and este_arbore_binar_de_cautare(arbore_binar["stanga"])
    if(arbore_binar["stanga"] is None and arbore_binar["dreapta"] is not None):
        return arbore_binar["valoare"] < arbore_binar["dreapta"]["valoare"] and este_arbore_binar_de_cautare(arbore_binar["dreapta"])
    if(arbore_binar["stanga"] is not None and arbore_binar["dreapta"] is not None):
        return arbore_binar["valoare"] > arbore_binar["stanga"]["valoare"] and arbore_binar["valoare"] < arbore_binar["dreapta"]["valoare"] and este_arbore_binar_de_cautare(arbore_binar["stanga"]) and este_arbore_binar_de_cautare(arbore_binar["dreapta"])

print(este_arbore_binar_de_cautare(arbore_binar_de_cautare))
print(este_arbore_binar_de_cautare(arbore_binar_de_necautare))
