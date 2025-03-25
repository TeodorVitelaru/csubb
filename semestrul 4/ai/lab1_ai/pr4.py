from collections import Counter


# complexitate: O(n), n-nr de cuvinte din string
def pr4(str):
    arr_cuv = str.split(" ")
    frecventa = {}
    for cuv in arr_cuv:
        if cuv not in frecventa:
            frecventa[cuv] = 1
        else:
            frecventa[cuv] += 1
    cuv_fara_frecventa = []
    for key in frecventa:
        if frecventa[key] == 1:
            cuv_fara_frecventa.append(key)
    return cuv_fara_frecventa

# la fel de eficient


def pr4_ai(text):
    frecventa = Counter(text.split())  # Numărăm aparițiile fiecărui cuvânt
    return [cuvant for cuvant, numar in frecventa.items() if numar == 1]


print(pr4("teodor teodor este"))
print(pr4_ai("teodor teodor este"))
