#O(n)-timp, O(1)-spatiu
def pr3(vect1, vect2):
    produs = 0
    for a, b in zip(vect1, vect2):
        if a!=0 and b!=0:
            produs += a*b
    return produs

#aceeasi complexitate ca mai sus
def pr3_ai(v1, v2):
    # Verificăm dacă vectorii au aceeași lungime
    if len(v1) != len(v2):
        raise ValueError("Vectorii trebuie să aibă aceeași lungime!")
    
    produs = 0
    for i in range(len(v1)):
        # Calculăm doar pentru elementele nenule
        if v1[i] != 0 and v2[i] != 0:
            produs += v1[i] * v2[i]
    
    return produs

print(pr3([1,0,2,0,3],[1,2,0,3,1]))
print(pr3_ai([1,0,2,0,3],[1,2,0,3,1]))