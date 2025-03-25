#complexitate: O(n), O(1)
def pr5(arr):
    suma = 0;
    n = len(arr)
    suma_corecta = (n * (n-1))//2
    for num in arr:
        suma += num;
    return suma-suma_corecta

#aceeasi rezolvare
def pr5_ai(arr):
    n = len(arr)  # Știm că sunt numere între 1 și n-1
    suma_ideala = (n - 1) * n // 2
    suma_real = sum(arr)
    return suma_real - suma_ideala


print(pr5([1,2,3,4,2]))
print(pr5_ai([1,2,3,4,2]))
