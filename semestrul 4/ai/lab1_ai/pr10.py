#O(n*m)-timpm O(1)-memorie
def pr10(matrice, n, m):
    for i in range(m):
        for j in range(n):
            if matrice[i][j] == 1:
                return j

#O(n*log(m))-timp, O(1)-spatiu
def pr10_ai(matrice):
    max_1uri = -1  # Valoare inițială foarte mică
    index_max = -1  # Indexul liniei cu cele mai multe 1-uri
    
    for i, linie in enumerate(matrice):
        # Căutăm prima valoare 1 în linie folosind căutare binară
        low, high = 0, len(linie) - 1
        first_1_position = len(linie)  # Dacă nu găsim niciun 1, returnăm dimensiunea liniei

        while low <= high:
            mid = (low + high) // 2
            if linie[mid] == 1:
                first_1_position = mid
                high = mid - 1  # Căutăm prima apariție a unui 1
            else:
                low = mid + 1
        
        numar_1uri = len(linie) - first_1_position  # Numărul de 1-uri din linie
        if numar_1uri > max_1uri:
            max_1uri = numar_1uri
            index_max = i
    
    return index_max

print(pr10([
[0,0,0,1,1],
[0,1,1,1,1],
[0,0,1,1,1]], 3, 4))

print(pr10_ai([
[0,0,0,1,1],
[0,1,1,1,1],
[0,0,1,1,1]]))