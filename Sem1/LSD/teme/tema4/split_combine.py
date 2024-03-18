def split(lista_perechi):
    return ( list ( map( lambda x : x[0], lista_perechi ) ), list ( map( lambda x : x[1], lista_perechi ) ) )

def combine(pereche_liste):
    return [ (pereche_liste[0][i], pereche_liste[1][i]) for i in range(len(pereche_liste[0])) ]

print(split([(1, 2), (3, 4), (5, 6)]))
print(combine(([1, 3, 5], [2, 4, 6])))
