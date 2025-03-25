
#Complexitate: O(n*m), n=nr de linii, m-nr de coloane
def pr9(matrice, coord1, coord2):
   suma = 0
   for i in range(coord1[0], coord2[0]+1):
       for j in range(coord1[1], coord2[1]+1):
           suma += matrice[i][j]
   return suma

#O(n*m)-timp, O(n*m)-spatiu
def pr9_ai(matrice, coord1, coord2):
    n = len(matrice)
    m = len(matrice[0])
    
    # Pas 1: Construim matricea de prefix sum
    prefix = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(n):
        for j in range(m):
            prefix[i + 1][j + 1] = matrice[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j]
    
    # Coordonatele primelor 2 puncte și ale celor două coordonate
    p, q = coord1
    r, s = coord2
    
    # Aplicăm formula pentru a calcula suma submatricei
    suma = prefix[r + 1][s + 1] - prefix[p][s + 1] - prefix[r + 1][q] + prefix[p][q]
    
    return suma

 

print(pr9([
[0, 2, 5, 4, 1],
[4, 8, 2, 3, 7],
[6, 3, 4, 6, 2],
[7, 3, 1, 8, 3],
[1, 5, 7, 9, 4]], [2,2], [4,4]))
print(pr9_ai([
[0, 2, 5, 4, 1],
[4, 8, 2, 3, 7],
[6, 3, 4, 6, 2],
[7, 3, 1, 8, 3],
[1, 5, 7, 9, 4]], [2,2], [4,4]))