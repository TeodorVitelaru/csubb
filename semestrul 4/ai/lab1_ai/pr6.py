
#O(n), O(n)--memorie
def pr6(arr):
    max_aparitii = 0;
    numar_cautat = 0;
    dict = {}
    for num in arr:
        if num not in dict:
            dict[num] = 1
            if dict[num] > max_aparitii:
                numar_cautat = num
        else:
            dict[num] += 1
            if dict[num] > max_aparitii:
                numar_cautat = num
    if dict[numar_cautat] > len(arr)/2:
        return numar_cautat
 
 #alogritmul lui Boyer-Moore(O(n), O(1)-memorie)
def pr6_ai(arr):
    # Faza 1: Alegem un candidat
    candidat, contor = None, 0
    
    for num in arr:
        if contor == 0:
            candidat = num
        contor += 1 if num == candidat else -1

    # Faza 2: Verificăm dacă este majoritar
    if arr.count(candidat) > len(arr) // 2:
        return candidat
    return None  # Nu există element majori   

print(pr6([2,8,7,2,2,5,2,3,1,2,2]))
print(pr6_ai([2,8,7,2,2,5,2,3,1,2,2]))