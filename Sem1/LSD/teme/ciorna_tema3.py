def progresie_aritmetica(n):
    if n == 0:
        return 2
    else:
        return 2 * progresie_aritmetica(n - 1) - 3

def suma_recursiva(n):
    if n == 1:
        return 1
    else:
        return n + suma_recursiva(n - 1)

def produsul_cifrelor(n):
    if n == 0:
        return 1
    else:
        return (n % 10) * produsul_cifrelor(int(n / 10))

def numarul_cifrelor(n):
    if n == 0:
        return 0
    else:
        return 1 + numarul_cifrelor(int(n / 10))

def numarul_cifrelor_pare(n):
    if n == 0:
        return 0
    else:
        return ( not ( (n % 10) % 2 ) ) + numarul_cifrelor_pare(int(n / 10))
    
def cifra_maxima(n):
    if n == 0:
        return 0
    else:
        return max( (n % 10), (cifra_maxima(int(n/10))) )

def ridicare_la_putere(a, n):
    if n == 0:
        return 1
    else:
        return a * ridicare_la_putere(a, n - 1)

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

def suma_Taylor(x, n, termen_putere, termen_factorial):
    if n == 0:
        return 1
    else:
        return (termen_putere / termen_factorial) + suma_Taylor(x, n - 1, (termen_putere / x), (termen_factorial / n))

def serie_Taylor(x, n):
    termen_putere = ridicare_la_putere(x, n)
    termen_factorial = factorial(n)

    return suma_Taylor(x, n, termen_putere, termen_factorial)

print(serie_Taylor(10, 171))
