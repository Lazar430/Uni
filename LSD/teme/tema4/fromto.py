def fromto(margine_inferioara, margine_superioara, divizor):
    return [i for i in range(margine_inferioara, margine_superioara + 1) if i % divizor == 0]

print(fromto(5, 15, 5))
