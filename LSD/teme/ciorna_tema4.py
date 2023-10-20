def split(lista_perechi):
    return ( list ( map( lambda x : x[0], lista_perechi ) ), list ( map( lambda x : x[1], lista_perechi ) ) )

print(split([(1, 2), (3, 4), (5, 6)]))
