import functools

def min_set(multime):
    return functools.reduce(lambda acc, curr: acc if acc < curr else curr, multime, multime.pop())

def ultimele_cifre(multime):
    return functools.reduce(lambda acc, curr: acc + [curr % 10], multime, [])

print(min_set({43, -23, 55, 10, 6, 2349, -6, 21}))
print(ultimele_cifre({123, 456, 789, 4932, 1230, 593, 3452}))
