# O(n)-timp, O(n)-spatiu
def pr8(n):
    numere = []
    for i in range(1, n+1):
        numar = i
        binar = ""
        while numar > 0:
            binar = str(numar % 2) + binar
            numar //= 2
        numere.append(binar)
    return numere

# O(n)-timp, O(n)-spatiu


def pr8_ai(n):
    binare = []
    for i in range(1, n + 1):
        binare.append(bin(i)[2:])  # Adăugăm fiecare valoare binară în listă
    return binare  # Returnăm lista cu numerele binare


print(pr8(4))
print(pr8_ai(4))
