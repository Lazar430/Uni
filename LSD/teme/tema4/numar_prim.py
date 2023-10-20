import math

def este_prim(numar):
    if numar == 0 or numar == 1:
        return False
    elif numar % 2 == 0 and numar != 2:
        return False
    else:
        for i in range(3, int(math.sqrt(numar)) + 1, 2):
            if (numar % i == 0):
                return False
    return True
