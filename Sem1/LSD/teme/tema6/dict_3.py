import functools

def update_dictionar(dictionar, item, conditie):
    if(conditie(item[1])):
        dictionar[item[0]] = item[1]
    return dictionar

def filter(dictionar, conditie):
    return functools.reduce(lambda acc, curr: update_dictionar(acc, curr, conditie) , dictionar.items(), {})

print(filter({'a': 5, 'b': 7, 'c': 1}, lambda x : x >= 5))
