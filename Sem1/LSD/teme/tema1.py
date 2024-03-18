def bisect(an):
    return (an % 4 == 0 and an % 100 != 0) or (an % 400 == 0)

def f(x):
    return 2*x + 1 if x < -3 else 0 if x == -3 else 3*(x**2) + 6*x - 5

def sort(a, b, c):
    return max(a, b, c), max(min(a, b), min(b, c), min(a, c)), min(a, b, c)
